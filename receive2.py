import ctypes
import serial
import time
import struct
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
    return x , y , z

ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_33395111002A0038-if00', 9600)
# ser = serial.Serial('/dev/pts/6')
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
class Data(ctypes.Structure):
    _fields_ = [
        ("baseLink", ctypes.c_double),
        ("turntableLink", ctypes.c_double),
        ("linkOne", ctypes.c_double),
        ("linkTwo", ctypes.c_double),
        ("pitch", ctypes.c_double),
        ("roll", ctypes.c_double),
        ("x", ctypes.c_double),
        ("y", ctypes.c_double),
        ("z", ctypes.c_double),
    ]

# datastruct = Data()
# def initialize():
#     datastruct.turntableLink = 0.2
#     datastruct.linkOne = 0.2
#     datastruct.linkTwo = 0.2
#     datastruct.pitch = 0.2
#     datastruct.roll = 0.2
#     datastruct.x = 0.5
#     datastruct.y = 0.5
#     datastruct.z = 0.5

def home():
    current = read()
    current.contents.x = 0.5
    current.contents.y = 0.5
    current.contents.z = 0.5 
    output = Calculate(current.contents.x , current.contents.y ,current.contents.z)
    send(output)

def read():
    if ser.in_waiting > 0:
        rcd = ser.read(74)
        if (rcd[-1] != 0):
            return
        decoded = cobs.decode(rcd[:-1])
        DataStruct = ctypes.cast(decoded, ctypes.POINTER(Data))
        return DataStruct
    else:
        print("Error recieving data")
        return


def Calculate(x , y , z):
    ikstruct = Data()
    ikstruct = read()
    ikstruct.contents.x = x
    ikstruct.contents.y = y
    ikstruct.contents.z = z
    dv = ctypes.c_double * 5
    r_dv = dv( ikstruct.contents.turntableLink , ikstruct.contents.linkOne , ikstruct.contents.linkTwo , ikstruct.contents.pitch , ikstruct.contents.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(ikstruct.contents.x , ikstruct.contents.y , ikstruct.contents.z)
    vone_size = ctypes.c_double * 2
    r_vone_size = vone_size(0.0, 0.0)
    vone_data = ctypes.c_double * 5
    r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0)
    lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double)]
    result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
    print("OUTPUT: ",*r_vone_data)
    return result

def send(datastruct):
    encoded_data = cobs.encode(bytearray(datastruct))
    print(encoded_data)
    ser.write(encoded_data)
    ser.write(bytearray([0]))
    print("Sent")


def main():
    controller=joystickinit()
    home()
    x = 0.5
    y = 0.5
    z = 0.5
    running = True
    newx = 0.0
    newy = 0.0
    newz = 0.0
    while running:
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

        output = Calculate(newx , newy , newz)
        send(output)
        x = newx
        y = newy
        z = newz

if __name__ =='__main__':
    main()
