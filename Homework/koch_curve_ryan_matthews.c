#include "FPToolkit.c"
void draw_koch_curve(double x1, double y1, double x2, double y2, int depth);
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
    G_rgb(1.0, 1.0, 1.0);
    double x1 = 100, y1 = 400;
    double x2 = 700, y2 = 400;
    draw_koch_curve(x1, y1, x2, y2, depth_val);
    G_wait_key();
    return 0;
}
void draw_koch_curve(double x1, double y1, double x2, double y2, int depth) {
    if (depth == 0) {
        G_line(x1, y1, x2, y2);
        return;
    }

    double x3 = x1 + (x2 - x1) / 3.0;
    double y3 = y1 + (y2 - y1) / 3.0;
    double x5 = x1 + 2.0 * (x2 - x1) / 3.0;
    double y5 = y1 + 2.0 * (y2 - y1) / 3.0;

    double dx = x5 - x3;
    double dy = y5 - y3;
    double x4 = x3 + dx * 0.5 - dy * sqrt(3) / 2.0;
    double y4 = y3 + dy * 0.5 + dx * sqrt(3) / 2.0;

    draw_koch_curve(x1, y1, x3, y3, depth - 1);
    draw_koch_curve(x3, y3, x4, y4, depth - 1);
    draw_koch_curve(x4, y4, x5, y5, depth - 1);
    draw_koch_curve(x5, y5, x2, y2, depth - 1);
}
