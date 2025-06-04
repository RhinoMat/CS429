from Gkit import *
from ctypes import *
from math import *
from random import *

WIDTH = 400
HEIGHT = 400

x : float = 0.0
y : float = 0.0

def translate(dx : float, dy : float):
    global x, y
    x += dx
    y += dy

def scale(sx : float, sy : float):
    global x, y
    x *= sx
    y *= sy

def rotate(theta : float):
    global x, y
    radians : float = theta * pi / 180.0
    c : float = cos(radians)
    s : float = sin(radians)
    temp : float = x * c - y * s
    y = x * s + y * c
    x = temp

def fern(r_f : float):
    if r_f < 0.01:
        # Stem: xn = 0.0; yn = 0.16*y;
        scale(0.0, 0.16)
    elif r_f < 0.86:
        # Main leaflets: xn = 0.85*x + 0.04*y; yn = -0.04*x + 0.85*y + 1.6;
        scale(0.85, 0.85)
        rotate(2.6926) # atan2(-0.04, 0.85) in degrees
        translate(0.0, 1.6)
    elif r_f < 0.93:
        # Left leaflets: xn = 0.20*x - 0.26*y; yn = 0.23*x + 0.22*y + 1.6;
        scale(0.2, 0.23)
        rotate(-52.125) # atan2(-0.26, 0.20) in degrees
        translate(0.0, 1.6)
    else:
        # Right leaflets: xn = -0.15*x + 0.28*y; yn = 0.26*x + 0.24*y + 0.44;
        scale(-0.15, 0.26)
        rotate(61.9275); # atan2(0.28, -0.15) in degrees
        translate(0.0, 0.44)

def main():
    G_init_graphics(WIDTH, HEIGHT)
    G_rgb(0.0, 0.0, 0.0)
    G_clear()
    G_rgb(0.0, 1.0, 0.0) # Green fern
    for k in range(0, 200000):
        r_f = random()
        fern(r_f)
        plot_x : float = (x + 2.1820) / (2.6558 + 2.1820) * WIDTH
        plot_x = WIDTH - plot_x
        plot_y = (y / 9.9983 * HEIGHT)
        G_point(plot_x, plot_y)
    G_save_to_bmp_file("FERN.bmp")

if __name__ == "__main__":
    main()