#include "FPToolkit.c"
void sierp(double x0, double y0, double x1, double y1, double x2, double y2, int depth);
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
    G_rgb(0.0, 0.0, 0.0); // White background
    G_clear();

    double length = 700.0;
    double p0[2] = {50, 50}; // Bottom-left vertex
    double p1[2] = {p0[0] + length, p0[1]}; // Bottom-right vertex
    double p2[2] = {p0[0] + length / 2, p0[1] + sin(M_PI / 3) * length}; // Top vertex

    G_rgb(0.0, 1.0, 0.0); // Dark green for the outer triangle
    G_triangle(p0[0], p0[1], p1[0], p1[1], p2[0], p2[1]);

    sierp(p0[0], p0[1], p1[0], p1[1], p2[0], p2[1], depth_val);

    G_wait_key();
    return 0;
}
void sierp(double x0, double y0, double x1, double y1, double x2, double y2, int depth)
{
    if (depth <= 0) return;
    // Calculate midpoints of the triangle's edges
    double midpoint1[2] = {(x0 + x1) / 2, (y0 + y1) / 2};
    double midpoint2[2] = {(x1 + x2) / 2, (y1 + y2) / 2};
    double midpoint3[2] = {(x0 + x2) / 2, (y0 + y2) / 2};
    G_rgb(0.0, 1.0, 0.0); 
    G_fill_triangle(midpoint1[0], midpoint1[1], midpoint2[0], midpoint2[1], midpoint3[0], midpoint3[1]);
    sierp(x0, y0, midpoint1[0], midpoint1[1], midpoint3[0], midpoint3[1], depth - 1);
    sierp(midpoint1[0], midpoint1[1], x1, y1, midpoint2[0], midpoint2[1], depth - 1);
    sierp(midpoint3[0], midpoint3[1], midpoint2[0], midpoint2[1], x2, y2, depth - 1);
    return;
}
