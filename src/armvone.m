function vone = armvone(q0, pos)
    % Import the robot
    arm = importrobot('ARMDIFF1.urdf', MeshPath='meshes');
    
    % Define the initial joint configuration as an array
    qInitial = struct(...
                'JointName', {'turntable_joint', 'linkOneJoint', 'linkTwoJoint', 'pitchJoint', 'rollJoint'},'JointPosition', num2cell(q0));
    %qInitial = q0; % q0 is already an array of joint positions
    
    % Create the IK solver
    ik = inverseKinematics('RigidBodyTree', arm);
    
    % Define the end-effector name (use the name from your URDF)
    endEffector = 'roll';
    
    % Define the weights for the IK solution
    weights = [1, 1, 1, 1, 1, 1]; % Adjust as necessary for your DOF
    
    % Solve the inverse kinematics
    %[newConfig, ~] = ik(endEffector, trvec2tform(pos), weights, qInitial);
    new = ik(endEffector,trvec2tform(pos), weights, qInitial);

    % Extract the new joint positions and return as an array
    %vone = [newConfig.JointPosition];d
    vone = [new(1).JointPosition new(2).JointPosition new(3).JointPosition new(4).JointPosition new(5).JointPosition];
end