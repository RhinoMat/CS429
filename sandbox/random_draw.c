#include "FPToolkit.c"
#define WIDTH 800
#define HEIGHT 800
double x = 0.0;
double y = 0.0;

void translate(double dx, double dy)
{
    x += dx;
    y += dy;
}
void scale(double sx, double sy)
{
    x *= sx;
    y *= sy;
}
void rotate(double theta)
{
    double radians, c, s, temp;
    radians = theta * M_PI / 180.0;
    c = cos(radians);
    s = sin(radians);
    temp = x*c - y*s;
    y = x*s + y*c;
    x = temp;
}
void F(double r)
{
    if (r < 0.5)
    {
        G_rgb(0.0, 1.0, 0.0);
        scale(0.5, 0.5);
    }
    else
    {
        G_rgb(1.0, 0.0, 1.0);
        scale(0.5, 0.5);
        translate(0.5, 0.5);
    }
}
int main()
{
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    for (int k = 0; k < 20000; k++)
    {
        double r_f;
        r_f = drand48();
        F(r_f);
        G_point(x*WIDTH, y*HEIGHT);
        
    }
    G_wait_key();
}