import numpy as np
import rerun as rr
import urdfpy
from receive2 import *
import pygame
from scipy.spatial.transform import Rotation as R
def visualize():
    links = {"base_link": 0, "turntable": 1, "linkOne":2, "linkTwo":3, "pitch":4, "roll":5}
    i = 0
    for link, transform in fk.items():
    i = links[link.name]
    translation = transform[:3, 3]
    rotation_matrix = transform[:3, :3]
    rotation = R.from_matrix(rotation_matrix)
    quat = rotation.as_quat()
    if i == 5:
            print(f"End-effector position: x={translation[0]:.3f}, y={translation[1]:.3f}, z={translation[2]:.3f}")
    rr.log("axis", rr.AnyValues(confidence=[translation[0],translation[1],translation[2]],description="Bla bla bla…",),)
    rr.log(mesh_location[i], rr.Transform3D(translation=translation , quaternion= quat))
    i = i + 1
rr.init('d30b95f5-15b8-4b2e-ac8c-12dc580be9a5', spawn=True)
rr.log_file_from_path('rerun_ARMDIFF.urdf')
mesh_location = [
    'meshes/base_link.STL',
    'meshes/turntable.STL',
    'meshes/linkOne.STL',
    'meshes/linkTwo.STL',
    'meshes/pitch.STL',
    'meshes/roll.STL'
]
for i in mesh_location:
    rr.log_file_from_path(i)
pygame.init()
pygame.joystick.init()
joystickinit()
file = open('rerun_ARMDIFF.urdf','r+')
robot = urdfpy.URDF.load(file)
lib = ctypes.CDLL("codegen/dll/armvone/armvone.so")
while True:
    global ikstruct
    ikstruct = Data()
    x = 1.0
    y = 0.0
    z = 0.5
    rollpos = 0
    running = True
    newx = 1.0
    newy = 0.0
    newz = 0.5
    newrollpos = 0
    ikstruct.turntableLink = 0
    ikstruct.linkOne = 0
    ikstruct.linkTwo = 0
    ikstruct.pitch = 0
    ikstruct.roll = 0
    controller=joystickinit()
    while running:
        diry , dirx , dirz , roll= joystickread(controller)
        if dirx > 0.5:
            newx = x - 0.001
        elif dirx < -0.5:
            newx = x + 0.001

        if diry > 0.5:
            newy = y - 0.001
        elif diry < -0.5:
            newy = y + 0.001

        if dirz > 0.5:
            newz = z + 0.001
        elif dirz < -0.5:
            newz = z - 0.001
        if roll > 0.5:
            newrollpos = rollpos + 0.05
        elif roll < -0.5:
            newrollpos = rollpos - 0.05
        ikstruct.contents.x = newx
        ikstruct.contents.y = newy
        ikstruct.contents.z = newz
        ikstruct.contents.roll = newrollpos
        x = newx
        y = newy
        z = newz
        if z >0.88:
            print("Approaching height limit")
        if x > 1:
            print("Approaching forward limit")
        rollpos = newrollpos
        # output = Calculate(ikstruct)
        print(f"x:{ikstruct.x:.2f} y:{ikstruct.y:.2f} z:{ikstruct.z:.2f} roll:{ikstruct.roll:.2f} ")
        time.sleep(0.01)
        ikstruct = read(ikstruct.x , ikstruct.y , ikstruct.z)
        visualize()
        output = Calculate(ikstruct)
        ikstruct.contents.turntableLink = output[0]
        ikstruct.contents.linkOne = output[1]
        ikstruct.contents.linkTwo = output[2]
        ikstruct.contents.pitch = output[3]
        ikstruct.contents.roll = newrollpos
        entity = [
            'rerun_ARMDIFF.urdf/base_link',
            'rerun_ARMDIFF.urdf/base_link/turntable',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch/roll'
        ]
        fk = robot.link_fk(cfg={'turntable_joint' : ikstruct.contents.turntableLink , 'linkOneJoint' : ikstruct.contents.linkOne , 'linkTwoJoint' : ikstruct.contents.linkTwo , 'pitchJoint' : ikstruct.contents.pitch , 'rollJoint' : ikstruct.contents.roll})
