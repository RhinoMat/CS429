from ctypes import *
from Gkit import *
from random import *
import numpy as np
def main():
    swidth = 800
    sheight = 800
    G_init_graphics(swidth, sheight)
    G_rgb(0, 0, 0)
    G_clear()

    start_r = random()
    start_g = random()
    start_b = random()
    end_r = random()
    end_g = random()
    end_b = random()
    for i in np.linspace(1, 0, num=1000):
        y_span = i * sheight
        red = start_r + i * (end_r - start_r)
        green = start_g + i * (end_g - start_g)
        blue = start_b + i * (end_b - start_b)
        G_rgb(red, green, blue)
        G_line(0.0, y_span, swidth, y_span)
    print(f"Initial: R: {start_r}, G: {start_g}, B:{start_b}; Ending: R: {end_r}, G: {end_g}, B: {end_b}")
    G_wait_key()
    G_save_to_bmp_file("blend_rand.bmp")
    return

if __name__ == "__main__":
    main()