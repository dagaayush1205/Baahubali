import ctypes
import serial
import time
import struct
from cobs import cobs


ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_33395111002A0038-if00', 9600)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
output_buffer = bytes(66)
class Data(ctypes.Structure):
    _fields_=[
        ("baseLink",ctypes.c_double),
        ("turntableLink", ctypes.c_double),
        ("linkOne" , ctypes.c_double),
        ("linkTwo" , ctypes.c_double),
        ("endeffector" , ctypes.c_double),
        ("x" , ctypes.c_double),
        ("y" , ctypes.c_double),
        ("z" , ctypes.c_double)]

DataStruct = Data()
def initialize():
    DataStruct.baseLink = 0.0
    DataStruct.turntableLink = 0.0
    DataStruct.linkOne = 0.0
    DataStruct.linkTwo = 0.0
    DataStruct.endeffector = 0.0
    DataStruct.x = 0.0
    DataStruct.y = 0.0
    DataStruct.z = 0.0

def read():
    rcd = ser.read(66)
    decoded = cobs.decode(rcd)
    some = ctypes.cast(decoded , ctypes.POINTER(Data))

def Calculate():
    dv = ctypes.c_double * 6
    r_dv = dv(DataStruct.baseLink , DataStruct.turntableLink , DataStruct.linkOne , DataStruct.linkTwo , DataStruct.endeffector)
    dv1 = ctypes.c_double * 3
    r_dv1 = dv1(DataStruct.x , DataStruct.y , DataStruct.z)
    vone_size = ctypes.c_double * 2
    r_vone_size = vone_size(0.0 , 0.0)
    vone_data = ctypes.c_double * 6
    r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
    lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double),ctypes.POINTER(ctypes.c_double)]
    result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
    print("OUTPUT: ",*r_vone_data)
    return result

def send(result):
    encoded_data = cobs.encode(bytearray(result))
    ser.write(encoded_data)

def main():
        read()
        test = Calculate()    
        send(test)
if __name__ =='__main__':
    main()
