
# ser = serial.Serial('/dev/ttyUSB1', 57600)
# data = ser.read(1).decode('ascii')
# print(data)
import ctypes
import serial
import struct
from cobs import cobs 
ser = serial.Serial('/dev/serial/by-id/usb-ZEPHYR_Team_RUDRA_Tarzan_33395111002A0038-if00', 9600)
class Data(ctypes.Structure):
    _fields_=[("a",ctypes.c_double),
              ("b",ctypes.c_double),
              ("c",ctypes.c_double),
              ("d",ctypes.c_double),
              ("e",ctypes.c_double),
              ("f",ctypes.c_double),
              ("g",ctypes.c_double),
              ("h",ctypes.c_double)]
# output_buffer = (ctypes.c_int *("n",ctypes.c_int) 12)()
#
# class sample(ctypes.Structure):
#     _fields_=[("x",ctypes.c_int),
#               ("y",ctypes.c_int),
#               ("z",ctypes.c_int)]
#
# sample(ctypes.c_int(0),ctypes.c_int(1),ctypes.c_int(2))
# sample_encoding = cobs.encode(sample)
# while True:
#     # data = cobs.encode(in_bytes="hel")
print("i am alive")
output_buffer = ser.read(66)
# sample_data = (1,2,3,4,5,6,7,8)
# sample_data_format = 'dddddddd'
# print("OUTPUT BUFFER: ", output_buffer)
# sample_data_binary = struct.pack(sample_data_format,*sample_data)
# encoded_data = cobs.encode(sample_data_binary)
# print("Cobs encoded data: ",encoded_data)
# decoded_data = cobs.decode(encoded_data)
output_buffer_decoded = cobs.decode(output_buffer)
print("output_buffer_decoded: ", output_buffer_decoded)
#unpack_data = struct.unpack(sample_data_format,decoded_data)
result = ctypes.cast(output_buffer_decoded, ctypes.POINTER(Data))
# Data = struct.unpack(sample_data_format,output_buffer_decoded)
# if unpack_data == sample_data:
#     print("success")
print(result.contents.a , result.contents.b , result.contents.c , result.contents.d , result.contents.e , result.contents.f , result.contents.g , result.contents.h)
