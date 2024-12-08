
% Test Script for armone

% Define the initial joint positions (q0) as a vector of 6 joint angles
q0 = [0,0,0,0,0,0]; % Example joint positions in radians

% Define the target end-effector position (pos) as a 3D vector
pos = [1,1,1]; % Example target position in meters (X, Y, Z)

% Call the armvone function with q0 and pos
vone = armvone(q0, pos);
