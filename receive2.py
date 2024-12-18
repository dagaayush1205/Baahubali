import ctypes
import math
import serial
import time
from cobs import cobs
import pygame

pygame.init()
pygame.joystick.init()

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
    for event in pygame.event.get():
        x = joystick.get_axis(0)
        y = joystick.get_axis(1)
        z = joystick.get_axis(2)
        print(f"x:{x:.2f} y:{y:.2f} z:{z:.2f} ")
    return 0 , 0 , z

ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_3339511100440022-if00', 9600)
# ser = serial.Serial('/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A50285BI-if00-port0', 57600)
# ser = serial.Serial('/dev/serial/by-id/usb-STMicroelectronics_STLINK-V3_002400433032511537333436-if02',9600)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
class Data(ctypes.Structure):
    _fields_ = [
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

def read():
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
        print(f"{dataStruct.contents.turntableLink:.2f}, "f"{dataStruct.contents.linkOne:.2f}, "f"{dataStruct.contents.linkTwo:.2f}, "f"{dataStruct.contents.pitch:.2f}, "f"{dataStruct.contents.roll:.2f}, "f"{dataStruct.contents.x:.2f}, "f"{dataStruct.contents.y:.2f}, "f"{dataStruct.contents.z:.2f}")
        return dataStruct


def Calculate(ikstruct):
    if ikstruct == None:
        return None
    dv = ctypes.c_double * 5
    r_dv = dv( ikstruct.contents.turntableLink , ikstruct.contents.linkOne , ikstruct.contents.linkTwo , ikstruct.contents.pitch , ikstruct.contents.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(ikstruct.contents.x , ikstruct.contents.y , ikstruct.contents.z)
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
            time.sleep(0.01)
        encoded_data = encoded_data + bytearray([0])
        # encoded_data = list(encoded_data)
        ser.write(encoded_data)
        # for x in encoded_data:
        #     ser.write(x)
        return True
    # if datastruct != None:
    #     encoded_data = cobs.encode(bytearray(datastruct))
    #     encoded_data = list(encoded_data)
    #     # print(encoded_data)
    #     for i in encoded_data:
    #         ser.write(i)
    #     ser.write(bytearray([0]))
    #     print("Sent")


def main():
    controller=joystickinit()
    ikstruct = Data()
    ikstruct = read()

    if not send(home(ikstruct)):
        print("Failed home")
    print("Moved to home command")
    x = 0.5
    y = 0.5
    z = 0.5
    running = True
    newx = 0.0
    newy = 0.0
    newz = 0.0
    while running:
        ikstruct = read()
        if ikstruct == None:
            print("Error: while reading, writing last received value")
            send(ikstruct)
        else:
            dirx , diry , dirz = joystickread(controller)
            if dirx > 0.3:
                newx = x+0.05
            elif dirx < -0.3:
                newx = x-0.05

            if diry > 0.3:
                newy = y+0.05
            elif diry < -0.3:
                newy = y-0.05

            if dirz > 0.3:
                newz = z+0.05
            elif dirz < -0.3:
                newz = z-0.05
            ikstruct.contents.x = newx
            ikstruct.contents.y = newy
            ikstruct.contents.z = newz

            output = Calculate(ikstruct)
            send(output)
            x = newx
            y = newy
            z = newz
        time.sleep(0.11)

if __name__ =='__main__':
    main()
    #
