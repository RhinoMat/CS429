from ctypes import *
from Gkit import *
import numpy as np
import random
from math import *
x: float = 0.0
y:float = 0.0
WIDTH: int = 1280
HEIGHT = 720
def translate(dx, dy):
    global x, y
    x += dx
    y += dy
def scale(sx, sy):
    global x, y
    x *= sx
    y *= sy
def rotate(theta):
    global x, y
    radians = theta * pi / 180.0
    c = cos(radians)
    s = sin(radians)
    temp = x*c - y*s
    y = x*s + y*c
    x = temp
def main():
    global x, y
    G_init_graphics(WIDTH, HEIGHT)
    G_rgb(0, 0, 0)
    G_clear()
    start_r = 0.2
    start_g = 0.2
    start_b = 0.2
    end_r = 1.0
    end_g = 0.0
    end_b = 0.0
    for i in np.linspace(1, 0, num=1000):
        y_span = i * HEIGHT
        red = start_r + i * (end_r - start_r)
        green = start_g + i * (end_g - start_g)
        blue = start_b + i * (end_b - start_b)
        G_rgb(red, green, blue)
        G_line(0.0, y_span, WIDTH, y_span)
    G_rgb(1, 0, 1)
    xn = 0.0
    yn = 0.0
    for i in range(20000000):
        r = random.random()
        if r < 0.01:
            xn = 0.0
            yn = 0.16*y
        elif r < 0.86:
            xn = 0.85 * x + 0.04 * y
            yn = -0.04 * x + 0.85 * y + 1.6
        elif r < 0.93:
            xn = 0.2 * x - 0.26 * y
            yn = 0.23 * x + 0.22 * y + 1.6
        else:
            xn = -0.15 * x + 0.28 * y
            yn = 0.26 * x + 0.24 * y + 0.44
        G_point(xn*WIDTH, yn*HEIGHT)
        x = xn
        y = yn

    #G_wait_key()
    G_save_to_bmp_file("Barn.bmp")
    return

if __name__ == "__main__":
    main()
