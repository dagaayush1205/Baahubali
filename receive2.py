import ctypes
import serial
import time
import struct
from cobs import cobs


ser = serial.Serial(
    '/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_33395111002A0038-if00', 9600, timeout=1, write_timeout=1)
# lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")


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

datastruct = Data()
def initialize():
    datastruct.turntableLink = 0.2
    datastruct.linkOne = 0.2
    datastruct.linkTwo = 0.2
    datastruct.pitch = 0.2
    datastruct.roll = 0.2
    datastruct.x = 0.5
    datastruct.y = 0.5
    datastruct.z = 0.5

def home():
    current = Data()
    current = read()

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


def Calculate():
    dv = ctypes.c_double * 5
    r_dv = dv( datastruct.turntableLink , datastruct.linkOne , datastruct.linkTwo , datastruct.pitch , datastruct.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(datastruct.x , datastruct.y , datastruct.z)
    vone_size = ctypes.c_double * 2
    r_vone_size = vone_size(0.0, 0.0)
    vone_data = ctypes.c_double * 5
    r_vone_data = vone_data(0.0, 0.0, 0.0, 0.0, 0.0)
    lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.POINTER(
        ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double)]
    result = lib.armvone(r_dv, r_dv1, r_vone_data, r_vone_size)
    print("OUTPUT: ", *r_vone_data)
    return result


def send():
    encoded_data = cobs.encode(bytearray(datastruct))
    print(encoded_data)
    ser.write(encoded_data)
    ser.write(bytearray([0]))
    print("Sent")


def main():
    initialize()
    home()
    # while True:
    # read()
    Calculate()
    send()
    time.sleep(0.001)

if __name__ == '__main__':
    main()
