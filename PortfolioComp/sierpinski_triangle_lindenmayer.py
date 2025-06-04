from Gkit import *
from math import *

def lsystem_expand(axiom, rules, depth):
    result = axiom
    for _ in range(depth):
        next_result = ""
        for char in result:
            next_result += rules.get(char, char)
        result = next_result
    return result

def color(i):
    if i % 3 == 0:
        G_rgb(1, 0, 0)
    elif i % 3 == 1:
        G_rgb(0, 1, 0)
    elif i % 3 == 2:
        G_rgb(0.5, 0, 0.5)

def draw_lsystem(instructions, angle, step, start_pos, start_angle):
    x, y = start_pos
    theta = start_angle
    for i, cmd in enumerate(instructions):
        color(i)
        if cmd == '+':
            theta += angle
        elif cmd == '-':
            theta -= angle
        elif cmd.isalpha():
            new_x = x + step * cos(theta)
            new_y = y + step * sin(theta)
            G_line(x, y, new_x, new_y)
            x, y = new_x, new_y

def main():
    swidth, sheight = 800, 700
    G_init_graphics(swidth, sheight)
    axiom = "A"
    rules = {'A': "B-A-B", 'B': "A+B+A"}
    depth = 6
    instructions = lsystem_expand(axiom, rules, depth)
    step = 10
    start_pos = (50, 50)
    start_angle = 0

    deg = 58
    count = 0
    while True:
        G_rgb(0, 0, 0)
        G_clear()
        angle = deg * pi / 180  # convert to radians
        draw_lsystem(instructions, angle, step, start_pos, start_angle)
        key = G_wait_key()
        if key == ord('q'):
            fname = f"stl{count:04d}.bmp"
            G_save_to_bmp_file(fname)
            #break
        deg += 2
        count += 1

if __name__ == "__main__":
    main()