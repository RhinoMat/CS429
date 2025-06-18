from Gkit import *
from ctypes import *
from math import *
from cmath import *
from random import *

#WIDTH = 800
#HEIGHT = 800
WIDTH = 1920
HEIGHT = 1080
def get_color(k, max_iter):
    t = k / max_iter
    # Example: smooth blue to red gradient
    r = t
    g = 0.2 * (1 - t)
    b = 1 - t
    return r, g, b

'''def main():
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
    G_save_to_bmp_file("julia.bmp")'''

def main():
    G_init_graphics(WIDTH, HEIGHT)
    G_rgb(0.3, 0.3, 0.3)
    G_clear()

    c = complex(-0.7, 0.27015)
    max_iter = 200

    num_frames = 60
    zoom = 1.0
    pan_x = 0.1
    pan_y = 0.0

    for frame in range(num_frames):
        G_clear()
        for x in range(WIDTH):
            for y in range(HEIGHT):
                a = (4.0 / (WIDTH * zoom)) * (x - WIDTH / 2) + pan_x
                b = (4.0 / (HEIGHT * zoom)) * (y - HEIGHT / 2) + pan_y
                z = complex(a, b)

                for k in range(max_iter):
                    z = z * z + c
                    if abs(z) >= 100:
                        break

                if k < max_iter - 1:
                    r, g, b = get_color(k, max_iter)
                    G_rgb(r, g, b)
                else:
                    G_rgb(0, 0, 0)
                G_point(x, y)
        G_save_to_bmp_file(f"Julia_shots/julia_{frame:03d}_{WIDTH}x{HEIGHT}.bmp")
        print(f"Julia_shots/julia_{frame:03d}_{WIDTH}x{HEIGHT}.bmp")
        #G_display_image()
        zoom *= 1.1  # Zoom in each frame

if __name__ == "__main__":
    main()