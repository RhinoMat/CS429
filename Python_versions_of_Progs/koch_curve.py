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
    G_rgb(1, 1, 1)
    x1 = 100
    y1 = 400
    x2 = 700
    y2 = 400
    koch_curve(x1, y1, x2, y2, depth)
    G_wait_key()
    G_save_to_bmp_file("koch.bmp")
    return

def koch_curve(x1, y1, x2, y2, depth):
    if depth == 0:
        G_line(x1, y1, x2, y2)
        return
    x3 = x1 + (x2 - x1) / 3.0
    y3 = y1 + (y2 - y1) / 3.0
    x5 = x1 + 2.0 * (x2 - x1) / 3.0
    y5 = y1 + 2.0 * (y2 - y1) / 3.0
    dx = x5 - x3
    dy = y5 - y3
    x4 = x3 + dx * 0.5 - dy * sqrt(3) / 2.0
    y4 = y3 + dy * 0.5 + dx * sqrt(3) / 2.0
    koch_curve(x1, y1, x3, y3, depth - 1)
    koch_curve(x3, y3, x4, y4, depth - 1)
    koch_curve(x4, y4, x5, y5, depth - 1)
    koch_curve(x5, y5, x2, y2, depth - 1)

if __name__ == "__main__":
    main()