from machine import Pin, I2C, UART
import utime, struct

i2c = I2C(1, sda=Pin(2), scl=Pin(3), freq=400000)
uart = UART(0, baudrate=115200)

MPU6050_ADDR = 0x68
PWR_MGMT_1   = 0x6B
ACCEL_XOUT_H = 0x3B
GYRO_XOUT_H  = 0x43

i2c.writeto_mem(MPU6050_ADDR, PWR_MGMT_1, b'\x00')

def read_raw(reg):
    h = i2c.readfrom_mem(MPU6050_ADDR, reg, 1)[0]
    l = i2c.readfrom_mem(MPU6050_ADDR, reg+1, 1)[0]
    val = (h << 8) | l
    if val > 32767:
        val -= 65536
    return val

def read_imu():
    ax = read_raw(ACCEL_XOUT_H)   / 16384.0
    ay = read_raw(ACCEL_XOUT_H+2) / 16384.0
    az = read_raw(ACCEL_XOUT_H+4) / 16384.0
    gx = read_raw(GYRO_XOUT_H)    / 131.0
    gy = read_raw(GYRO_XOUT_H+2)  / 131.0
    gz = read_raw(GYRO_XOUT_H+4)  / 131.0
    t  = (read_raw(0x41)/340.0) + 36.53
    return (ax, ay, az, gx, gy, gz, t)

def crc_arc(data):
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if (crc & 1) else crc >> 1
    return crc & 0xFFFF

def cobs_encode(data):
    out = bytearray()
    start = 0
    for i, b in enumerate(data):
        if b == 0:
            out.append(i - start + 1)
            out.extend(data[start:i])
            start = i + 1
    out.append(len(data) - start + 1)
    out.extend(data[start:])
    out.append(0)
    return bytes(out)

while True:
    imu_vals = read_imu()

    diffdrive = (0.0, 0.0)
    inv = tuple(0.0 for _ in range(8))
    imu = imu_vals
    msg_type = 1 

    msg_wo_crc = struct.pack(
        '<2f8d7fI',
        *diffdrive,
        *inv,
        *imu,
        msg_type
    )

    crc16 = crc_arc(msg_wo_crc)
    crc32 = crc16 & 0xFFFF
    msg_full = msg_wo_crc + struct.pack('<I', crc32)

    encoded = cobs_encode(msg_full)
    uart.write(encoded)

    utime.sleep(0.05)
