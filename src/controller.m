joy = vrjoystick(1);
while true
    [axes, buttons] = read(joy);
    disp(axes(1));
    pause(0.1);
end
