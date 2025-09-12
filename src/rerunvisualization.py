import numpy as np
import rerun as rr
import urdfpy
from receive2 import *
import pygame
from scipy.spatial.transform import Rotation as R
rr.init('d30b95f5-15b8-4b2e-ac8c-12dc580be9a5', spawn=True)
rr.log_file_from_path('rerun_ARMDIFF.urdf')

#keyboard 
mesh_location = [
    'meshes/base_link.STL',
    'meshes/turntable.STL',
    'meshes/linkOne.STL',
    'meshes/linkTwo.STL',
    'meshes/pitch.STL',
    'meshes/roll.STL'
]
keyboard_origin = np.array([1.0, 0.0, 0.5])  # position of bottom-left corner of the keyboard
key_spacing = 0.025  # spacing between keys
rows = ["QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"]

tilt_deg_x = 90
tilt_deg_z = 90
rotation = R.from_euler('xz', [tilt_deg_x, tilt_deg_z], degrees=True)

quat = rotation.as_quat()

for row_index, row in enumerate(rows):
    for col_index, key in enumerate(row):
        local_pos = np.array([col_index * key_spacing, -row_index * key_spacing, 0])
        rotated_pos = rotation.apply(local_pos)
        world_pos = keyboard_origin + rotated_pos

        rr.log(
            f"keyboard/{key}",
            rr.Boxes3D(half_sizes=[[0.01, 0.01, 0.005]]),
            rr.Transform3D(
                translation=world_pos,
                quaternion=quat
            )
        )
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
    z = 0.0
    running = True
    newx = 1.0
    newy = 0.0
    newz = 0.0
    ikstruct = read()
    controller=joystickinit()
    links = {"base_link": 0, "turntable": 1, "linkOne":2, "linkTwo":3, "pitch":4, "roll":5}
    I = [[-1,0,0,0],
            [0,1,0,0],
            [0,0,-1,0],
            [0,0,0,1]]
    for link, transform in fk.items():
        i = links[link.name]
        translation = transform[:3, 3]
        rotation_matrix = transform[:3, :3]
        rotation = R.from_matrix(rotation_matrix)
        quat = rotation.as_quat()
        if i == 5:
                print(f"End-effector position: x={translation[0]:.3f}, y={translation[1]:.3f}, z={translation[2]:.3f}")
                x = translation[0]
                y = translation[1]
                z = translation[2]
        rr.log(mesh_location[i], rr.Transform3D(translation=translation , quaternion= quat))
        i = i + 1
    while running:
        dirx , diry , dirz = joystickread(controller)
        if dirx > 0.5:
            newx = x + 0.001
        elif dirx < -0.5:
            newx = x - 0.001

        if diry > 0.5:
            newy = y + 0.001
        elif diry < -0.5:
            newy = y - 0.001

        if dirz > 0.5:
            newz = z + 0.001
        elif dirz < -0.5:
            newz = z - 0.001
        ikstruct.contents.x = newx
        ikstruct.contents.y = newy
        ikstruct.contents.z = newz
        x = newx
        y = newy
        z = newz
        ikstruct = read()
        # output = Calculate(ikstruct)
        print(f"x:{ikstruct.x:.2f} y:{ikstruct.y:.2f} z:{ikstruct.z:.2f} ")
        if round(ikstruct.x, 2) == 0.77 and round(ikstruct.y, 2) == 0.00 and round(ikstruct.z, 2) == 0.42:
            print("f key pressed")
            key_pressed = "F"
            rr.log("keyboard/keypress", rr.TextDocument(f"Key pressed: {key_pressed}"))
        time.sleep(0.01)
        output = Calculate(ikstruct)
        ikstruct.contents.turntableLink = output[0]
        ikstruct.contents.linkOne = output[1]
        ikstruct.contents.linkTwo = output[2]
        ikstruct.contents.pitch = output[3]
        ikstruct.contents.roll = output[4]
        fk = robot.link_fk(cfg={'turntable_joint' : ikstruct.contents.turntableLink , 'linkOneJoint' : ikstruct.contents.linkOne , 'linkTwoJoint' : ikstruct.contents.linkTwo , 'pitchJoint' : ikstruct.contents.pitch , 'rollJoint' : ikstruct.contents.roll})
        i = 0
        entity = [
            'rerun_ARMDIFF.urdf/base_link',
            'rerun_ARMDIFF.urdf/base_link/turntable',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch',
            'rerun_ARMDIFF.urdf/base_link/turntable/linkOne/linkTwo/pitch/roll'
        ]
        links = {"base_link": 0, "turntable": 1, "linkOne":2, "linkTwo":3, "pitch":4, "roll":5}
        I = [[-1,0,0,0],
             [0,1,0,0],
             [0,0,-1,0],
             [0,0,0,1]]
        for link, transform in fk.items():
            i = links[link.name]
            translation = transform[:3, 3]
            rotation_matrix = transform[:3, :3]
            rotation = R.from_matrix(rotation_matrix)
            quat = rotation.as_quat()
            if i == 5:
                    print(f"End-effector position: x={translation[0]:.3f}, y={translation[1]:.3f}, z={translation[2]:.3f}")

            rr.log(mesh_location[i], rr.Transform3D(translation=translation , quaternion= quat))
            i = i + 1
            ikstruct.contents.type = 1.0
            if send(ikstruct):
                print("out success")
