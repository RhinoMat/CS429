// mandelbrot set, complex number system
// black is divergence
// blue is convergence
#include "FPToolkit.c"
#include <complex.h>
int main()
{
    double sheight = 800, swidth = 800;
    G_init_graphics(swidth, sheight);
    G_rgb(0.3, 0.3, 0.3);
    G_clear();
    complex z, c;
    double a = 0;
    double b = 0;
    c = a+b*I;
    for (double x = 0; x < swidth; x++)
    {
        for (double y = 0; y < sheight; y++)
        {
            z = 0;
            a = (4/sheight)*(x-sheight/2);
            b = (4/swidth)*(y-swidth/2);
            c = a+b*I;
            for (double k = 0; k < 200; k++)
            {
                z = z*z+c;
            }
            if (cabs(z) >= 100)
                G_rgb(0.7, 0, 0.7);
            else
                G_rgb(0, 0, 0);
            G_point(x, y);
        }
    }
    G_wait_key();
    G_save_to_bmp_file("mand.bmp");
}