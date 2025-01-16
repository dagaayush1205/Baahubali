import ctypes
import math
import serial
import time
from cobs import cobs
import pygame
import threading
import urdfpy
pygame.init()
pygame.joystick.init()

def init_visualization():
    global robot 
    robot = urdfpy.URDF.load('rerun_ARMDIFF.urdf')
    print("Available links found:")
    for link in robot.links:
        print(link.name)

def visualization():
    while True: 
        robot.show(cfg={ 'turntable_joint' : ikstruct.turntableLink , 'linkOneJoint' : ikstruct.linkOne , 'linkTwoJoint' : ikstruct.linkTwo , 'pitchJoint' : ikstruct.pitch , 'rollJoint' : ikstruct.roll})

def joystickinit():
    if pygame.joystick.get_count() == 0:
        print("No joystick detected!")
        pygame.quit()
        exit()
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"Joystick '{joystick.get_name()}' initialized")
    return joystick

def joystickread(joystick):
    x = 0
    y = 0
    z = 0
    pygame.event.get()
    x = joystick.get_axis(0)
    y = joystick.get_axis(1)
    z = joystick.get_axis(2)
    roll = joystick.get_axis(3)
    # print(f"x:{x:.2f} y:{y:.2f} z:{z:.2f} ")
    return x , y , z , roll

# ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_3339511100440022-if00', 9600)
# ser = serial.Serial('/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A50285BI-if00-port0', 57600)
# ser = serial.Serial('/dev/serial/by-id/usb-STMicroelectronics_STLINK-V3_002400433032511537333436-if02',9600)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
class Data(ctypes.Structure):
    _fields_ = [
        ("linearx" , ctypes.c_float),
        ("lineary" , ctypes.c_float),
        ("turntableLink", ctypes.c_double),
        ("linkOne", ctypes.c_double),
        ("linkTwo", ctypes.c_double),
        ("pitch", ctypes.c_double),
        ("roll", ctypes.c_double),
        ("x", ctypes.c_double),
        ("y", ctypes.c_double),
        ("z", ctypes.c_double),
    ]

def home(ikstruct):
    ikstruct.contents.x = 0.5
    ikstruct.contents.y = 0.5
    ikstruct.contents.z = 0.5
    output = Calculate(ikstruct)
    return output

def read(x , y , z):
    dataStruct = Data() 
    # while (rcd[-1] != 0)
    rcd = ser.read(66)
    if rcd[-1] != 0:
        for i, v in enumerate(map(int, rcd)):
            if v == 0x00:
                kcd = ser.read(i+1)
                temp = rcd[i+1:]
                rcd = temp + kcd
                break
    decoded = cobs.decode(rcd[:-1])
    dataStruct = ctypes.cast(decoded, ctypes.POINTER(Data))
    print("READ:")
    dataStruct.contents.x = x
    dataStruct.contents.y = y
    dataStruct.contents.z = z
    print(f"{dataStruct.contents.turntableLink:.2f}, "f"{dataStruct.contents.linkOne:.2f}, "f"{dataStruct.contents.linkTwo:.2f}, "f"{dataStruct.contents.pitch:.2f}, "f"{dataStruct.contents.roll:.2f}, "f"{dataStruct.contents.x:.2f}, "f"{dataStruct.contents.y:.2f}, "f"{dataStruct.contents.z:.2f}")
    return dataStruct


def Calculate(ikstruct):
    if ikstruct == None:
        return None
    dv = ctypes.c_double * 5
    r_dv = dv(ikstruct.turntableLink , ikstruct.linkOne , ikstruct.linkTwo , ikstruct.pitch , ikstruct.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(ikstruct.x , ikstruct.y , ikstruct.z)
    vone_size = ctypes.c_double * 2
    r_vone_size = vone_size(0.0, 0.0)
    vone_data = ctypes.c_double * 5
    r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0)
    lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double)]
    lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
    print("OUTPUT: ",*r_vone_data)
    return r_vone_data

def send(datastruct):
    timeout = 1
    start_time = time.time()
    if datastruct != None:
        result = Data(*datastruct)
        b = bytearray(result)
        encoded_data = cobs.encode(b)
        while ser.out_waiting > 0:
            if time.time() - start_time > timeout:
                print("Write operation timed out due to full buffer.")
                return False
            # time.sleep(0.01)
        encoded_data = encoded_data + bytearray([0])
        # encoded_data = list(encoded_data)
        ser.write(encoded_data)
        print("sent")
        # for x in encoded_data:
        
        #     ser.write(x)
        # print(binascii.hexlify(encoded_data))
        return True
    # if datastruct != None:
    #     encoded_data = cobs.encode(bytearray(datastruct))
    #     encoded_data = list(encoded_data)
        # print(encoded_data)
    #     for i in encoded_data:
    #         ser.write(i)
    #     ser.write(bytearray([0]))
    #     print("Sent")
def inverse():
    prev_ikstruct = ikstruct
    # if not send(home(ikstruct)):
    #     print("Failed home")
    x = 0.0
    y = 0.0
    z = 0.0
    running = True
    newx = 0.0
    newy = 0.0
    newz = 0.0
    controller=joystickinit()
    while running:
        # while math.sqrt((ikstruct.contents.linkOne - prev_ikstruct.contents.linkOne)**2 + (ikstruct.contents.linkTwo - prev_ikstruct.contents.linkTwo)**2) > 0.1:
           # ikstruct = read()
        dirx , diry , dirz = joystickread(controller)
        if dirx > 0.5:
            newx = x + 0.001
        elif dirx < -0.5:
            newx = x - 0.001

        if diry > 0.5:
            newy = y + 0.001
        elif diry < -0.5:
            newy = y - 0.001

        if dirz > 0.5:
            newz = z + 0.001
        elif dirz < -0.5:
            newz = z - 0.001
        ikstruct.x = newx
        ikstruct.y = newy
        ikstruct.z = newz
        x = newx
        y = newy
        z = newz
        output = Calculate(ikstruct)
        # print(output)
        ikstruct.turntableLink = output[0]
        ikstruct.linkOne = output[1]
        ikstruct.linkTwo = output[2]
        ikstruct.pitch = output[3]
        ikstruct.roll = output[4]
        # send(output)
        print(output , newx , newy , newz)
    time.sleep(0.11)

def main():
    init_visualization()
    global ikstruct 
    ikstruct = Data()
    ikstruct.x
    # ikstruct = read()
    inverseTask = threading.Thread(target=inverse , name = 'inverseTask')
    visualizationTask = threading.Thread(target=visualization , name = 'visualizationTask')
    inverseTask.start()
    visualizationTask.start()

if __name__ =='__main__':
    main()
