from Gkit import *
from ctypes import *
from math import *
#include "FPToolkit.c"
class Production:
    def __init__(self, var='', axiom='', rule=''):
        self.var = var
        self.axiom = axiom
        self.rule = rule

prd = [Production() for _ in range(10)]
rule_num = 0
u = ""
v = ""
angle = 0.0
gangle = 0.0
flen = 0.0
depth = 0

'''
//  plant requires a global stack to be implemented because 
//  [ means put turtle's current location and angular 
//  direction on the stack, and ] means pop info from stack and 
//  position the turtle according to the location and angular 
//  information popped.
'''

def square_wave():
    global gangle, angle, rule_num, prd
    gangle = 90
    angle = 90
    rule_num = 0

    prd[rule_num].axiom = "A"
    rule_num += 1

    prd[rule_num].var = 'A'
    prd[rule_num].rule = "f-f-B"
    rule_num += 1

    prd[rule_num].var = 'B'
    prd[rule_num].rule = "f+f+A"
    rule_num += 1

def print_string(u):
    print(u)

def find_rule(s):
    for k in range(1, rule_num):
        if prd[k].var == s:
            return k
    return -1

def string_builder():
    global u, v, depth, prd, rule_num

    u = prd[0].axiom  # Initialize `u` with the axiom
    print_string(u)  # Print the initial axiom

    for _ in range(depth):  # Iterate for the specified depth
        v = ""  # Reset `v` for the new generation
        for char in u:  # Iterate through each character in `u`
            loc = find_rule(char)  # Find the rule for the character
            if loc != -1:
                v += prd[loc].rule  # Append the rule to `v`
            else:
                v += char  # Append the character itself if no rule is found
        u = v  # Update `u` with the new generation
        print_string(u)  # Print the new generation
        print("\n")  # Add a newline for readability


'''def autoplacer(swidth, sheight, p):
    """
    Automatically places points within the given screen width and height.
    Adjusts the scaling factor and offsets to fit the points on the screen.

    Args:
        swidth (int): Screen width.
        sheight (int): Screen height.
        p (list): List of points to be placed, where each point is a tuple (x, y).
    """
    # Find the bounding box of the points
    min_x = min(point[0] for point in p)
    max_x = max(point[0] for point in p)
    min_y = min(point[1] for point in p)
    max_y = max(point[1] for point in p)

    # Calculate the width and height of the bounding box
    bbox_width = max_x - min_x
    bbox_height = max_y - min_y

    # Determine the scaling factor to fit the points within the screen
    scale_x = swidth / bbox_width
    scale_y = sheight / bbox_height
    scale = min(scale_x, scale_y)  # Use the smaller scale to maintain aspect ratio

    # Calculate offsets to center the points on the screen
    offset_x = (swidth - bbox_width * scale) / 2 - min_x * scale
    offset_y = (sheight - bbox_height * scale) / 2 - min_y * scale

    # Apply the scaling and offsets to each point
    for i in range(len(p)):
        x, y = p[i]
        p[i] = (x * scale + offset_x, y * scale + offset_y)
'''

def string_interpreter():
    global u, flen, gangle

    # Initialize graphics
    G_init_graphics(800, 800)
    G_clear()
    G_rgb(0, 0, 0)  # Set background color to black
    G_rgb(1, 1, 1)  # Set drawing color to white

    # Starting position
    x, y = 400, 400
    angle = 90  # Initial angle
    stack = []  # Stack to store position and angle for '[' and ']'

    for char in u:
        if char == 'f':  # Move forward
            new_x = x + flen * cos(radians(angle))
            new_y = y + flen * sin(radians(angle))
            G_line(x, y, new_x, new_y)  # Draw a line
            x, y = new_x, new_y
        elif char == '+':  # Turn left
            angle += gangle
        elif char == '-':  # Turn right
            angle -= gangle
        elif char == '[':  # Save the current state
            stack.append((x, y, angle))
        elif char == ']':  # Restore the last saved state
            x, y, angle = stack.pop()

    G_display_image()  # Display the final image
    G_wait_key()  # Wait for user input before closing
def main():
    global flen, gangle, depth
    flen = 10
    gangle = 90
    depth = int(input("Please specify the level of depth for the l-system: "))
    square_wave()
    string_builder()
    print("Generated L-System String:", u)  # Debug: Print the generated string
    string_interpreter()
if __name__ == "__main__":
    main()