import ctypes
import serial
import time
import struct
from cobs import cobs


ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_33395111002A0038-if00', 9600)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
class Data(ctypes.Structure):
    _fields_=[
        ("turntableLink", ctypes.c_double),
        ("linkOne" , ctypes.c_double),
        ("linkTwo" , ctypes.c_double),
        ("pitch" , ctypes.c_double),
        ("roll" , ctypes.c_double),
        ("x" , ctypes.c_double),
        ("y" , ctypes.c_double),
        ("z" , ctypes.c_double),
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

def read():
    rcd = ser.read(74)
    print(rcd)
    decoded = cobs.decode(rcd)

    DataStruct = ctypes.cast(decoded , ctypes.POINTER(Data))
    print(DataStruct.contents.turntableLink , DataStruct.contents.linkOne , DataStruct.contents.linkTwo , DataStruct.contents.pitch , DataStruct.contents.roll , DataStruct.contents.x , DataStruct.contents.y , DataStruct.contents.z)
    return DataStruct
def Calculate():
    dv = ctypes.c_double * 5
    r_dv = dv( DataStruct.turntableLink , DataStruct.linkOne , DataStruct.linkTwo , DataStruct.pitch , DataStruct.roll)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(DataStruct.x , DataStruct.y , DataStruct.z)
    vone_size = ctypes.c_double * 2
    r_vone_size = vone_size(0.0 , 0.0)
    vone_data = ctypes.c_double * 5
    r_vone_data = vone_data( 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
    lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double)]
    result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
    print("OUTPUT: ",*r_vone_data)
    return result

def send():
    encoded_data = cobs.encode(bytearray(DataStruct))
    print(encoded_data)
    ser.write(encoded_data)
    ser.write(bytearray([0]))
    print("Sent")

def main():
    initialize()
    # while True:
    # read()
    Calculate()
    # while True:
    #     send()
    #     time.sleep(2.0)
        # test = Calculate() 
        # send(test)
if __name__ =='__main__':
    main()
