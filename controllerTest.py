import pygame

# Initialize pygame and its joystick module
pygame.init()
pygame.joystick.init()

# Check if at least one joystick is connected
if pygame.joystick.get_count() == 0:
    print("No joystick connected!")
    pygame.quit()
    exit()

# Select the first joystick
joystick = pygame.joystick.Joystick(0)
joystick.init()

# Display joystick info
print(f"Joystick Name: {joystick.get_name()}")
print(f"Number of Axes: {joystick.get_numaxes()}")
print(f"Number of Buttons: {joystick.get_numbuttons()}")

# Game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Handle joystick events
        # if event.type == pygame.JOYAXISMOTION:
            # Detect axis movement
        axis_value = joystick.get_axis(0)
        print(f"Axis {1} value: {axis_value:.2f}")

        # elif event.type == pygame.JOYBUTTONDOWN:
        #     # Detect button press
        #     print(f"Button {event.button} pressed")
        #
        # elif event.type == pygame.JOYBUTTONUP:
        #     # Detect button release
        #     print(f"Button {event.button} released")
        #
        # elif event.type == pygame.JOYHATMOTION:
        #     # Detect D-pad (hat) movement
        #     print(f"Hat {event.hat} moved to {event.value}")

# Cleanup
joystick.quit()
pygame.quit()

