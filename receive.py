# ser = serial.Serial('/dev/ttyUSB1', 57600)
# data = ser.read(1).decode('ascii')
# print(data)
import ctypes
import serial
import struct
from cobs import cobs 
ser = serial.Serial('/dev/pts/4', 57600)
class data(ctypes.Structure):
    _fields_=[("x",ctypes.c_int),
              ("y",ctypes.c_int),
              ("z",ctypes.c_int)]

# output_buffer = (ctypes.c_int * 12)()
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
output_buffer = ser.read(254)
sample_data = (1,2,3,4,5,6,7,8,9)
sample_data_format = 'IIIIIIIII'
sample_data_binary = struct.pack(sample_data_format,*sample_data)
encoded_data = cobs.encode(sample_data_binary)
print("Cobs encoded data: ",encoded_data)
decoded_data = cobs.decode(encoded_data)
unpack_data = struct.unpack(sample_data_format,decoded_data)
if unpack_data == sample_data:
    print("success")
print(unpack_data)
print(unpack_data[1])
    #
    # try :
    #     # decoded_data = bytes(output_buffer)
    #     # result = struct.unpack(int , output_buffer,)
    #     decoded_msg = struct.unpack('f f f',decoded_data)
    #     data = cobs.decode(sample_encoding)
    # except cobs.DecodeError :
    #     print("decoding DecodeError")
    # print("Received data: ", data)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")

dv = ctypes.c_double * 6
r_dv = dv(unpack_data[0] , unpack_data[1] , unpack_data[2] , unpack_data[3] , unpack_data[4] , unpack_data[5])
print("dv sent: ",*r_dv)
vone_data = ctypes.c_double * 6
r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
dv1 = ctypes.c_double * 3
r_dv1 = dv1(unpack_data[6] , unpack_data[7] , unpack_data[8])
print("dv1 sent: ",*r_dv1)
vone_size = ctypes.c_double * 2
r_vone_size = vone_size(0.0 , 0.0)

lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double)]
result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
print (*r_vone_data)
print("result: ",result)
output_struct = struct.pack('ffffff',*r_vone_data)
output_cobs_encoding = cobs.encode(output_struct)
print("encoded data: ",output_cobs_encoding)
ser.write(output_cobs_encoding)

# class inv(object):
#     def __init__(self):
#         self.obj = lib.inv_new()
#     def myFunction(self):
#         lib.main
