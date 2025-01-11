import numpy as np
import rerun as rr
import urdfpy
from receive2 import *
import pygame
from scipy.spatial.transform import Rotation as R
import trimesh
rr.init('d30b95f5-15b8-4b2e-ac8c-12dc580be9a5', spawn=True)
rr.log_file_from_path('rerun_ARMDIFF.urdf')
pygame.init()
pygame.joystick.init()
joystickinit()
file = open('rerun_ARMDIFF.urdf','r+')
robot = urdfpy.URDF.load(file)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
while True:
    global ikstruct
    ikstruct = Data()
    x = 0.0
    y = 0.0
    z = 0.0
    running = True
    newx = 0.0
    newy = 0.0
    newz = 0.0
    ikstruct.turntableLink = 1
    ikstruct.linkOne = 1
    ikstruct.linkTwo = 1
    ikstruct.pitch = 1
    ikstruct.roll = 1
    controller=joystickinit()
    while running:
        diry , dirx , dirz = joystickread(controller)
        if dirx > 0.5:
            newx = x + 0.01
        elif dirx < -0.5:
            newx = x - 0.01

        if diry > 0.5:
            newy = y + 0.01
        elif diry < -0.5:
            newy = y - 0.01

        if dirz > 0.5:
            newz = z + 0.01
        elif dirz < -0.5:
            newz = z - 0.01
        ikstruct.x = newx
        ikstruct.y = newy
        ikstruct.z = newz
        x = newx
        y = newy
        z = newz
        # output = Calculate(ikstruct)
        print(f"x:{ikstruct.x:.2f} y:{ikstruct.y:.2f} z:{ikstruct.z:.2f} ")
        time.sleep(0.11)
        output = Calculate(ikstruct)

        ikstruct.turntableLink = output[0]
        ikstruct.linkOne = output[1]
        ikstruct.linkTwo = output[2]
        ikstruct.pitch = output[3]
        ikstruct.roll = output[4]
        fk = robot.link_fk(cfg={ 'turntable_joint' : ikstruct.turntableLink , 'linkOneJoint' : ikstruct.linkOne , 'linkTwoJoint' : ikstruct.linkTwo , 'pitchJoint' : ikstruct.pitch , 'rollJoint' : ikstruct.roll})
        i = 0
        mesh_location = [
            'meshes/base_link.STL',
            'meshes/turntable.STL',
            'meshes/linkOne.STL',
            'meshes/linkTwo.STL',
            'meshes/pitch.STL',
            'meshes/roll.STL'
        ]
        entity = [
            'rerun_ARMDIFF.urdf/base_link',
            'rerun_ARMDIFF.urdf/base_link/turntable',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch/roll'
        ]
        for i, (link, transform) in enumerate(fk.items()):
            translation = transform[:3, 3]
            rotation_matrix = transform[:3, :3]
            rotation = R.from_matrix(rotation_matrix)
            print(link)
            quat = rotation.as_quat()
            rr.log_file_from_path(mesh_location[i])
            rr.log(mesh_location[i], rr.Transform3D(translation=translation , quaternion= quat))

        time.sleep(0.1)
0

