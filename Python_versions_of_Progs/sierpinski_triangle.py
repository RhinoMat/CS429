from ctypes import *
from Gkit import *
from math import *
def main():
    swidth = 800
    sheight = 800
    depth = 0
    while depth <= 0:
        depth = int(input("Please enter the depth of the Sierpinski Triangle: "))
    G_init_graphics(swidth, sheight)
    G_rgb(0, 0, 0)
    G_clear()
    length = 700
    p0 = [50, 50]
    p1 = [p0[0] + length, p0[1]]
    p2 = [p0[0] + length / 2, p0[1] + sin(pi / 3) * length]
    G_rgb(0, 1, 0)
    G_triangle(p0[0], p0[1], p1[0], p1[1], p2[0], p2[1])
    sierp(p0[0], p0[1], p1[0], p1[1], p2[0], p2[1], depth)
    G_wait_key()
    G_save_to_bmp_file("sierp.bmp")

def sierp(x0, y0, x1, y1, x2, y2, depth):
    if depth <= 0: 
        return
    midpoint1 = [(x0 + x1) / 2, (y0 + y1) / 2]
    midpoint2 = [(x1 + x2) / 2, (y1 + y2) / 2]
    midpoint3 = [(x0 + x2) / 2, (y0 + y2) / 2]
    G_rgb(0.0, 1.0, 0.0)
    G_fill_triangle(midpoint1[0], midpoint1[1], midpoint2[0], midpoint2[1], midpoint3[0], midpoint3[1])
    sierp(x0, y0, midpoint1[0], midpoint1[1], midpoint3[0], midpoint3[1], depth - 1)
    sierp(midpoint1[0], midpoint1[1], x1, y1, midpoint2[0], midpoint2[1], depth - 1)
    sierp(midpoint3[0], midpoint3[1], midpoint2[0], midpoint2[1], x2, y2, depth - 1)
    return

if __name__ == "__main__":
    main()