# ser = serial.Serial('/dev/ttyUSB1', 57600)
# data = ser.read(1).decode('ascii')
# print(data)
import ctypes
import serial
import struct
import time
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
class Out(ctypes.Structure):
    _fields_=[("a",ctypes.c_double),
              ("b",ctypes.c_double),
              ("c",ctypes.c_double),
              ("d",ctypes.c_double),
              ("e",ctypes.c_double),
              ("f",ctypes.c_double),
              ("g",ctypes.c_double),
              ("h",ctypes.c_double)]
Sample_send = Out()
Sample_send.a = 8.0
Sample_send.b = 0.0
Sample_send.c = 0.0
Sample_send.d = 4.0
Sample_send.e = 5.0
Sample_send.f = 10.0
Sample_send.g = 15.0
Sample_send.h = 20.0
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
output_buffer = bytes(66)
sample_data = (1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0 , 7.0 , 8.0)
sample_data_format = 'dddddddd'
# print("OUTPUT BUFFER: ", output_buffer)
encoded_data = cobs.encode(bytearray(Sample_send))
print(list(encoded_data))
encoded_data = encoded_data + bytes([0])
# print(f"Cobs encoded data: {0:x}",encoded_data)
# breakpoint()
# decoded_data = cobs.decode(encoded_data)
# output_buffer_decoded = cobs.decode(output_buffer)
# print("output_buffer_decoded: ", output_buffer_decoded)
#unpack_data = struct.unpack(sample_data_format,decoded_data)
# result = ctypes.cast(output_buffer_decoded, ctypes.POINTER(Data))
# Data = struct.unpack(sample_data_format,output_buffer_decoded)
# if unpack_data == sample_data:
#     print("success")
# print(result.contents.a , result.contents.b , result.contents.c , result.contents.d , result.contents.e , result.contents.f , result.contents.g , result.contents.h)
print("Writing data: ",encoded_data)
ser.setDTR(True)
ser.setRTS(True)
while True:
    ser.write(encoded_data)
    time.sleep(1.0)
    print("Sent")
    ser.write(encoded_data)
    print("Sent")
    time.sleep(1.0)
# # print(unpack_data[1])
#     #
#     # try :
#     #     # decoded_data = bytes(output_buffer)
#     #     # result = struct.unpack(int , output_buffer,)
#     #     decoded_msg = struct.unpack('f f f',decoded_data)
#     #     data = cobs.decode(sample_encoding)
#     # except cobs.DecodeError :
#     #     print("decoding DecodeError")
#     # print("Received data: ", data)
# lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
# #
# dv = ctypes.c_double * 6
# r_dv = dv(result.contents.a , result.contents.b , result.contents.c , result.contents.d , result.contents.e , result.contents.f)
# print("dv sent: ",*r_dv)
# vone_data = ctypes.c_double * 6
# r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
# dv1 = ctypes.c_double * 3
# r_dv1 = dv1(0.5 , 0.5 , 0.5)
# print("dv1 sent: ",*r_dv1)
# vone_size = ctypes.c_double * 2
# r_vone_size = vone_size(0.0 , 0.0)
# #
# lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double)]
# result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
# print (*r_vone_data)
# print("result: ",result)
# output_struct = struct.pack('ffffff',*r_vone_data)
# output_cobs_encoding = cobs.encode(output_struct)
# print("encoded data: ",output_cobs_encoding)
# # ser.write(output_cobs_encoding)
# #
# # # class inv(object):
# # #     def __init__(self):
# # #         self.obj = lib.inv_new()
# # #     def myFunction(self):
# # #         lib.main
bytesarray
