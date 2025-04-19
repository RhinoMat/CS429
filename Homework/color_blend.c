#include "FPToolkit.c"
int main()
{
    double swidth = 800, sheight = 800;
    G_init_graphics(swidth, sheight);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    double start_r = 0.2;
    double start_g = 0.2;
    double start_b = 0.2;
    double end_r = 1.0;
    double end_g = 0.0;
    double end_b = 0.0;
    for (double i = 1; i >= 0; i -= 0.001)
    {
        double y_span = 0 + i * (sheight - 0);
        double red = start_r + i * (end_r - start_r);
        double green = start_g + i * (end_g - start_g);
        double blue = start_b + i * (end_b - start_b);
        G_rgb(red, green, blue);
        G_line(0.0, y_span, swidth, y_span);
    }
    G_wait_key();
    G_save_to_bmp_file("color_blend.bmp");
    return 0;
}