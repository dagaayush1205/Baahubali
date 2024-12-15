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


DataStruct = Data()


def initialize():
    DataStruct.turntableLink = 0.2
    DataStruct.linkOne = 0.2
    DataStruct.linkTwo = 0.2
    DataStruct.pitch = 0.2
    DataStruct.roll = 0.2
    DataStruct.x = 0.5
    DataStruct.y = 0.5
    DataStruct.z = 0.5


<< << << < HEAD


== == == =


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
    r_dv = dv(DataStruct.turntableLink, DataStruct.linkOne,
              DataStruct.linkTwo, DataStruct.pitch, DataStruct.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(DataStruct.x, DataStruct.y, DataStruct.z)
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
    timeout = 1
    start_time = time.time()
    while ser.out_waiting > 0:
        if time.time() - start_time > timeout:
            print("Write operation timed out due to full buffer.")
            return False
        time.sleep(0.01)
    encoded_data = cobs.encode(bytearray(DataStruct))
    encoded_data = encoded_data + bytearray([0])
    encoded_data = list(encoded_data)
    for x in encoded_data:
        ser.write(x)
    print("Sent")


def main():
    initialize()


while True:
    read()
    Calculate()
    send()
    time.sleep(0.001)

if __name__ == '__main__':
    main()
