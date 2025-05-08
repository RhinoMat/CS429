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
void line(double r)
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
void square(double r)
{
    if (r < 0.25)
    {
        G_rgb(0.0, 1.0, 0.0);
        scale(0.5, 0.5);
    }
    else if (r < 0.5)
    {
        G_rgb(0.0, 1.0, 1.0);
        scale(0.5, 0.5);
        translate(0, 0.5);
    }
    else if (r < 0.75)
    {
        G_rgb(1.0, 0.0, 1.0);
        scale(0.5, 0.5);
        translate(0.5, 0);
    }
    else
    {
        G_rgb(0.0, 0.0, 1.0);
        scale(0.5, 0.5);
        rotate(180);
        translate(0.5, 0.5);
    }
}
void koch_curve(double r)
{
    if (r < 0.25)
    {
        G_rgb(0.0, 1.0, 0.0);
        scale(1/3.0, 1/3.0);
    }
    else if (r < 0.5)
    {
        G_rgb(0.0, 1.0, 1.0);
        scale(1/3.0, 1/3.0);
        rotate(60);
        translate(1/3.0, 0);
    }
    /*else if (r < 0.75)
    {
        G_rgb(1.0, 0.0, 1.0);
        scale(0.5, 0.5);
        translate(0.5, 0);
    }*/
    else if (r < 0.75)
    {
        G_rgb(1.0, 0.0, 1.0);
        scale(1/3.0, 1/3.0);
        rotate(-60);
        translate(1/3.0, 0);
    }
    else
    {
        G_rgb(1.0, 1.0, 0.0);
        scale(1/3.0, 1/3.0);
        translate(2/3.0, 0.0);
    }
}
int main()
{
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < 20000; k++)
        {
            double r_f;
            r_f = drand48();
            //line(r_f);
            //square(r_f);
            koch_curve(r_f);
            G_point(x*WIDTH, y*HEIGHT);
        }
    }
    
    G_wait_key();
}