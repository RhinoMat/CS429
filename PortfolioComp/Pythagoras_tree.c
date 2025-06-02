/*
    Pythagoras Tree fractal based graphic for the final portfolio project.
    Utilizes recursion to make a tree out of descending triangles.
    Fractal Type: Recursive
*/
#include "FPToolkit.c"
void pythagoras_tree(double x, double y, double size, double angle, double colorRed, double colorGreen, double colorBlue, int depth);
int main()
{
    double swidth = 800, sheight = 800;
    int depth_val = 0;
    printf("Please enter the depth of the Sierpinski Triangle: ");
    if (scanf("%d", &depth_val) != 1 || depth_val < 0) {
        printf("Invalid input. Depth must be a positive integer.\n");
        return 0;
    }
    G_init_graphics(swidth, sheight);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    for (int i = depth_val; i >= 0; i--)
    {
        srand(time(NULL));
        double color_r = (double)rand() / RAND_MAX;
        double color_g = (double)rand() / RAND_MAX;
        double color_b = (double)rand() / RAND_MAX;
        pythagoras_tree(400, 100, 100, 0, color_r, color_g, color_b, i);
        G_wait_key();
    }
    //G_rgb(0.0, 1.0, 0.0);
    //pythagoras_tree(400, 100, 100, 0, depth_val);
    G_wait_key();
    G_save_to_bmp_file("pythag.bmp");
    return 0;
}
void pythagoras_tree(double x, double y, double size, double angle, double colorRed, double colorGreen, double colorBlue, int depth) {
    if (depth == 0) return;

    // Square base (corner x, y), oriented at angle
    double x1 = x + size * cos(angle);
    double y1 = y + size * sin(angle);
    double x2 = x1 - size * sin(angle);
    double y2 = y1 + size * cos(angle);
    double x3 = x - size * sin(angle);
    double y3 = y + size * cos(angle);

    double square_x[4] = {x, x1, x2, x3};
    double square_y[4] = {y, y1, y2, y3};

    G_rgb(colorRed, colorGreen, colorBlue);
    G_fill_polygon(square_x, square_y, 4);
    G_rgb(0, 0, 0);
    G_polygon(square_x, square_y, 4);

    // Vector from x3 to x2 (top of the square)
    double dx = x2 - x3;
    double dy = y2 - y3;

    // Top point of the triangle (forms a right isosceles triangle)
    double x4 = x3 + (dx - dy) / 2;
    double y4 = y3 + (dx + dy) / 2;

    double tri_x[3] = {x3, x2, x4};
    double tri_y[3] = {y3, y2, y4};

    G_rgb(colorRed, colorGreen, colorBlue);
    G_fill_polygon(tri_x, tri_y, 3);
    G_rgb(0, 0, 0);
    G_polygon(tri_x, tri_y, 3);

    // Recursive calls: left and right branches
    double new_size = size / sqrt(2);

    pythagoras_tree(x3, y3, new_size, angle + M_PI/4, colorRed, colorGreen, colorBlue, depth - 1);
    pythagoras_tree(x4, y4, new_size, angle - M_PI/4, colorRed, colorGreen, colorBlue, depth - 1);
}