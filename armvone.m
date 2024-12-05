function vone = armvone(q0, pos)
    % Import the robot
    arm = importrobot('ARMYPR6.urdf', mesh='meshes');
    
    % Define the initial joint configuration (use names from your URDF)
    qInitial = struct(...
        'JointName', {'turntablejoint', 'joint1', 'joint2', 'pitchJoint', 'yawjoint', 'roll joint'},'JointPosition', num2cell(q0));
    
    % Create the IK solver
    ik = inverseKinematics('RigidBodyTree', arm);
    
    % Define the end-effector name (use the name from your URDF)
    endEffector = 'roll'; 
    
    % Define the weights for the IK solution
    weights = [0, 0, 0, 1, 1, 1]; % Adjust as necessary for your DOF
    
    % Solve the inverse kinematics
    [newConfig, ~] = ik(endEffector, trvec2tform(pos), weights, qInitial);
    
    % Extract the new joint positions
    vone = newConfig;
    %vone = struct(...
    %    'JointName', {'turntablejoint', 'joint1', 'joint2', 'pitchJoint', 'yawjoint', 'roll joint'},'JointPosition', newConfig.JointPosition);
end
