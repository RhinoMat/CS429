from Gkit import *
from ctypes import *
from math import *

from random import *

def main():
    swidth : float = 800 
    sheight : float = 800
    depth_val : int = 0
    #printf("Please enter the depth of the Sierpinski Triangle: ");
    #if (scanf("%d", &depth_val) != 1 || depth_val < 0) {
    #    printf("Invalid input. Depth must be a positive integer.\n");
    #    return 0;
    #}
    depth_val = int(input("Please enter the depth of the Sierpinski Triangle: "))
    if depth_val < 0: return
    G_init_graphics(swidth, sheight)
    G_rgb(0.0, 0.0, 0.0)
    G_clear()
    for i in range(depth_val, -1, -1):
        color_r : float = random()
        color_g : float = random()
        color_b : float = random()
        pythagoras_tree(400, 100, 100, 0, color_r, color_g, color_b, i)
        G_wait_key()
    G_wait_key()
    G_save_to_bmp_file("pythag.bmp")
    return
def pythagoras_tree(x : float, y : float, size : float, angle : float, colorRed : float, colorGreen : float, colorBlue : float, depth : int):
    if depth == 0: return

    # Square base (corner x, y), oriented at angle
    x1 : float = x + size * cos(angle)
    y1 : float = y + size * sin(angle)
    x2 : float = x1 - size * sin(angle)
    y2 : float = y1 + size * cos(angle)
    x3 : float = x - size * sin(angle)
    y3 : float = y + size * cos(angle)

    square_x : list[float] = [x, x1, x2, x3]
    square_y : list[float] = [y, y1, y2, y3]

    G_rgb(colorRed, colorGreen, colorBlue)
    G_fill_polygon(square_x, square_y)
    G_rgb(0, 0, 0)
    G_polygon(square_x, square_y)

    # Vector from x3 to x2 (top of the square)
    dx : float = x2 - x3
    dy : float = y2 - y3

    # Top point of the triangle (forms a right isosceles triangle)
    x4 : float = x3 + (dx - dy) / 2
    y4 : float = y3 + (dx + dy) / 2

    tri_x : list[float] = [x3, x2, x4]
    tri_y : list[float] = [y3, y2, y4]

    G_rgb(colorRed, colorGreen, colorBlue)
    G_fill_polygon(tri_x, tri_y)
    G_rgb(0, 0, 0)
    G_polygon(tri_x, tri_y)

    # Recursive calls: left and right branches
    new_size : float = size / sqrt(2)

    pythagoras_tree(x3, y3, new_size, angle + pi/4, colorRed, colorGreen, colorBlue, depth - 1)
    pythagoras_tree(x4, y4, new_size, angle - pi/4, colorRed, colorGreen, colorBlue, depth - 1)

if __name__ == "__main__":
    main()