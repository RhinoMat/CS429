from Gkit import *
from math import *
from colorsys import hsv_to_rgb

def lsystem_expand(axiom, rules, depth):
    result = axiom
    for _ in range(depth):
        next_result = ""
        for char in result:
            next_result += rules.get(char, char)
        result = next_result
    return result

def color(i, total):
    t = i / total
    r, g, b = hsv_to_rgb(t, 1, 1)
    G_rgb(r, g, b)

def draw_lsystem(instructions, angle, step, start_pos, start_angle):
    x, y = start_pos
    theta = start_angle
    total = len(instructions)
    for i, cmd in enumerate(instructions):
        color(i, total)
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
    swidth, sheight = 800, 800
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
        G_rgb(34/255, 34/255, 34/255)
        G_clear()
        angle = deg * pi / 180  # convert to radians
        draw_lsystem(instructions, angle, step, start_pos, start_angle)
        key = G_wait_key()
        if key == ord('q'):
            fname = f"stl{count:04d}.bmp"
            G_save_to_bmp_file(fname)
        else:
            deg += 2
            count += 1

if __name__ == "__main__":
    main()