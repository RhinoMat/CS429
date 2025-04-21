from ctypes import *
from Gkit import *
from math import *
from random import *
import numpy as np
def main():
    swidth = 800
    sheight = 800
    G_init_graphics(swidth, sheight)
    G_rgb(0, 0, 0)
    G_clear()

    start_r = 0.2
    start_g = 0.2
    start_b = 0.2
    end_r = 1.0
    end_g = 0.0
    end_b = 0.0
    for i in np.linspace(1, 0, num=1000):
        y_span = i * sheight
        red = start_r + i * (end_r - start_r)
        green = start_g + i * (end_g - start_g)
        blue = start_b + i * (end_b - start_b)
        G_rgb(red, green, blue)
        G_line(0.0, y_span, swidth, y_span)

    G_wait_key()
    G_save_to_bmp_file("blend.bmp")
    return

if __name__ == "__main__":
    main()