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
    if (depth <= 0) return;
    double x1 = x + size * cos(angle);
    double y1 = y + size * sin(angle);
    double x2 = x1 - size * sin(angle);
    double y2 = y1 + size * cos(angle);
    double x3 = x - size * sin(angle);
    double y3 = y + size * cos(angle);
    double square_x[] = {x, x1, x2, x3};
    double square_y[] = {y, y1, y2, y3};
    G_rgb(colorRed, colorGreen, colorBlue);
    G_fill_polygon(square_x, square_y, 4);
    G_rgb(0.0, 0.0, 0.0);
    G_polygon(square_x, square_y, 4);
    double x4 = x2 + (x3 - x) * cos(M_PI / 4) - (y3 - y) * sin(M_PI / 4);
    double y4 = y2 + (x3 - x) * sin(M_PI / 4) + (y3 - y) * cos(M_PI / 4);
    double triangle_x[] = {x2, x3, x4};
    double triangle_y[] = {y2, y3, y4};
    G_rgb(colorRed, colorGreen, colorBlue);
    G_fill_polygon(triangle_x, triangle_y, 3);
    G_rgb(0.0, 0.0, 0.0);
    G_polygon(triangle_x, triangle_y, 3);
    pythagoras_tree(x3, y3, size * 0.7, angle + M_PI / 4, colorRed, colorGreen, colorBlue, depth - 1);
    pythagoras_tree(x4, y4, size * 0.7, angle - M_PI / 4, colorRed, colorGreen, colorBlue, depth - 1);
}
