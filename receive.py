# import serial
# ser = serial.Serial('/dev/ttyUSB1', 57600)
# data = ser.read(1).decode('ascii')
# print(data)
import ctypes
import os

lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")

#breakpoint()
dv = ctypes.c_double * 6
r_dv = dv(0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
vone_data = ctypes.c_double * 6
r_vone_data = vone_data(0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0)
dv1 = ctypes.c_double * 3
r_dv1 = dv1(0.5 , 0.5 , 0.5)
vone_size = ctypes.c_double * 2
r_vone_size = vone_size(0.0 , 0.0)

lib.armvone.argtypes = [ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double) , ctypes.POINTER(ctypes.c_double)]
result = lib.armvone(r_dv , r_dv1 , r_vone_data , r_vone_size)
print (*r_vone_data)
print(result)
# class inv(object):
#     def __init__(self):
#         self.obj = lib.inv_new()
#     def myFunction(self):
#         lib.main
