from Gkit import *
from ctypes import *
from math import *
from cmath import *
from random import *

WIDTH = 800
HEIGHT = 800

def main():
    G_init_graphics(WIDTH, HEIGHT)
    G_rgb(0.3, 0.3, 0.3)
    G_clear()

    c = complex(-0.7, 0.27015)  # Julia set constant

    for x in range(WIDTH):
        for y in range(HEIGHT):
            # Map pixel to complex plane
            a = (4.0 / WIDTH) * (x - WIDTH / 2)
            b = (4.0 / HEIGHT) * (y - HEIGHT / 2)
            z = complex(a, b)

            for k in range(200):
                z = z * z + c
                if abs(z) >= 100:
                    break

            if k < 199:
                G_rgb(0.7, 0, 0.7)  # diverges (purple)
            else:
                G_rgb(0, 0, 0)      # converges (black)
            G_point(x, y)

    G_wait_key()
    G_save_to_bmp_file("julia.bmp")

if __name__ == "__main__":
    main()