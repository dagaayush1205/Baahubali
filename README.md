An inverse kinematics solution for R25 - Baahubali

# Introduction
Software system for simulating a 6-DoF robotic arm with real-time visualization and inverse kinematics. Utilizes MATLAB and SolidWorks to model kinematics, validate joint limits, and refine motion trajectories. Implements analytical IK algorithms to achieve precise end-effector control and realistic movement coordination.
<!---->
<!-- This uses MATLAB inverse kinematics solver to create a inverse kinematics solution for the robotics arm. The arm was designed in SolidWorks from where a .urdf file was generated to allow it to be used by the IK solver of MATLAB. After a successful version of the solver was generated it was converted to C code using the C code generator of MATLAB. The output code of matlab was in object file in this case it was armvone.so. It contained functions through which  -->

