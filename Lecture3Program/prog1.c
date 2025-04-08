#include "FPToolkit.c"
int main()
{
    double swidth, sheight;
    swidth = 800;
    sheight = 800;
    G_init_graphics(swidth, sheight);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    double r = 350;
    double center = swidth/2;
    for (double X = -r; X <= r; X += 0.01)
    {
        double uy = sqrt(r*r - X*X);
        double ly = -uy;
        G_rgb(1.0, 1.0, 1.0);
        G_circle(X+center, uy+center, 2);
        G_rgb(1.0, 1.0, 1.0);
        G_circle(X+center, ly+center, 2);
        
    }
    G_wait_key();
}