from ctypes import *
from Gkit import *
from math import *
from random import *
def main():
    swidth = 800
    sheight = 800
    depth = 0
    while depth <= 0:
        depth = int(input("Please enter the depth of the Pythagoras Tree: "))
    G_init_graphics(swidth, sheight)
    G_rgb(0, 0, 0)
    G_clear()
    for i in range(depth, 0, -1):
        color_r = random()
        color_g = random()
        color_b = random()
        pythagoras_tree(400, 100, 100, 0, color_r, color_g, color_b, i)
        G_wait_key()
    G_wait_key()
    G_save_to_bmp_file("pythag.bmp")
    return

def pythagoras_tree(x, y, size, angle, colorRed, colorGreen, colorBlue, depth):
    if depth <= 0: return
    x1 = x + size * cos(angle)
    y1 = y + size * sin(angle)
    x2 = x1 - size * sin(angle)
    y2 = y1 + size * cos(angle)
    x3 = x - size * sin(angle)
    y3 = y + size * cos(angle)
    square_x = [x, x1, x2, x3]
    square_y = [y, y1, y2, y3]
    G_rgb(colorRed, colorGreen, colorBlue)
    G_fill_polygon(square_x, square_y)
    G_rgb(0.0, 0.0, 0.0)
    G_polygon(square_x, square_y)
    x4 = x2 + (x3 - x) * cos(pi / 4) - (y3 - y) * sin(pi / 4)
    y4 = y2 + (x3 - x) * sin(pi / 4) + (y3 - y) * cos(pi / 4)
    triangle_x = [x2, x3, x4]
    triangle_y = [y2, y3, y4]
    G_rgb(colorRed, colorGreen, colorBlue)
    G_fill_polygon(triangle_x, triangle_y)
    G_rgb(0.0, 0.0, 0.0)
    G_polygon(triangle_x, triangle_y)
    pythagoras_tree(x3, y3, size * 0.7, angle + pi / 4, colorRed, colorGreen, colorBlue, depth - 1)
    pythagoras_tree(x4, y4, size * 0.7, angle - pi / 4, colorRed, colorGreen, colorBlue, depth - 1)

if __name__ == "__main__":
    main()