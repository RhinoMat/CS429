from Gkit import *
from ctypes import *
from math import *
from random import *
import numpy as np

WIDTH = 800
HEIGHT = 600

# Draw a single Cantor set segment recursively
def cantor(x : float, y : float, length : float, depth : int):
    if depth == 0: return
    if depth % 2 == 0:
        G_rgb(1, 0, 1)
    else:
        G_rgb(1, 1, 0)
    # Draw the current segment
    G_fill_rectangle(x, y, length, 10)

    # Recurse for left and right thirds, skipping the middle third
    next_y : float = y - 15
    if next_y > 0:
        cantor(x, next_y, length / 3.0, depth - 1)
        cantor(x + 2 * length / 3.0, next_y, length / 3.0, depth - 1)

def flip_cantor(x : float, y : float, length : float, depth : int):
    if depth == 0: return
    if depth % 2 == 0:
        G_rgb(1, 0, 1)
    else:
        G_rgb(1, 1, 0)
    # Draw the current segment
    G_fill_rectangle(x, y, length, 10)

    # Recurse for left and right thirds, skipping the middle third
    next_y : float = y + 15
    if next_y < HEIGHT:
        flip_cantor(x, next_y, length / 3.0, depth - 1)
        flip_cantor(x + 2 * length / 3.0, next_y, length / 3.0, depth - 1)

def main():
    G_init_graphics(WIDTH, HEIGHT)
    G_rgb(0, 0, 0) # White background
    #G_rgb(255.0 / 255.0, 151.0 / 255.0, 0.0 / 255.0)
    G_clear()
    start_r = 0.098
    start_g = 0.098
    start_b = 0.439
    end_r = 1.0
    end_g = 0.592
    end_b = 0.0
    for i in np.linspace(1, 0, num=1000):
        y_span = i * HEIGHT
        red = start_r + i * (end_r - start_r)
        green = start_g + i * (end_g - start_g)
        blue = start_b + i * (end_b - start_b)
        G_rgb(red, green, blue)
        G_line(0.0, y_span, WIDTH, y_span)
    G_rgb(128.0/255.0, 64.0/255.0, 5.0/255.0)
    G_fill_rectangle(0, HEIGHT / 2 - 35, WIDTH, 80)
    G_rgb(1, 1, 0)
    G_fill_circle(30, 30, 20)
    G_rgb(1, 1, 0)
    G_fill_circle(30, HEIGHT - 30, 20)
    G_rgb(0, 0, 0) # Black for Cantor set
    for _ in range(100):
        x = uniform(0, WIDTH)
        y = uniform(0, HEIGHT // 4)
        G_rgb(1, 1, 1)
        G_fill_circle(x, y, 2.5)

    # Start drawing from the top
    cantor(50, HEIGHT - 175, WIDTH - 100, 6)
    flip_cantor(50, 175, WIDTH - 100, 6)
    G_save_to_bmp_file("CANTOR.bmp")
    G_wait_key()

if __name__ == "__main__":
    main()