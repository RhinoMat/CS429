// julia set, complex number system
// black is divergence
// purple is convergence
#include "FPToolkit.c"
#include <complex.h>
int main()
{
    double sheight = 800, swidth = 800;
    G_init_graphics(swidth, sheight);
    G_rgb(0.3, 0.3, 0.3);
    G_clear();

    // Julia set constant (try different values for different patterns)
    complex c = -0.7 + 0.27015*I;

    for (double x = 0; x < swidth; x++)
    {
        for (double y = 0; y < sheight; y++)
        {
            // Map pixel to complex plane
            double a = (4.0/swidth)*(x-swidth/2);
            double b = (4.0/sheight)*(y-sheight/2);
            complex z = a + b*I;

            int k;
            for (k = 0; k < 200; k++)
            {
                z = z*z + c;
                if (cabs(z) >= 100) break;
            }
            if (k < 200)
                G_rgb(0.7, 0, 0.7); // diverges
            else
                G_rgb(0, 0, 0);     // converges
            G_point(x, y);
        }
    }
    G_wait_key();
    G_save_to_bmp_file("julia.bmp");
}