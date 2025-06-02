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
void initials(double r_f)
{
    if (r_f < 0.1 && r_f >= 0.0) { 
        scale(0.5, 0.5);
        translate(0.0, 0.5);
    }
    else if (r_f < 0.2 && r_f >= 0.1) {
        scale(0.5, 0.5);
        translate(0.0, 0.75);
    }
    else if (r_f < 0.3 && r_f >= 0.2) {
        scale(0.5, 0.5);
        rotate(45);
        translate(0.0, 0.0);
    }
    else if (r_f < 0.4 && r_f >= 0.3) {
        scale(0.5, 0.5);
        translate(0.5, 0.5);
    }
    else if (r_f < 0.5 && r_f >= 0.4) {
        scale(0.5, 0.5);
        translate(0.5, 0.75);
    }
    else if (r_f < 0.6 && r_f >= 0.5) { 
        scale(0.5, 0.5);
        translate(0.5, 0.625);
    }
    else if (r_f < 0.7 && r_f >= 0.6) { 
        scale(0.5, 0.5);
        translate(0.5, 0.5);
    }
    else if (r_f < 0.8 && r_f >= 0.7) { 
        scale(0.5, 0.5);
        translate(0.75, 0.5);
    }
    else if (r_f < 0.9 && r_f >= 0.8) { 
        scale(0.5, 0.5);
        translate(0.875, 0.5);
    }
    else { 
        scale(0.5, 0.5);
        translate(0.8125, 0.75);
    }
}
int main()
{
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    G_rgb(1.0, 1.0, 0.0);
    for (int k = 0; k < 200000; k++)
    {
        double r_f;
        r_f = drand48();
        initials(r_f);
        G_point(x*WIDTH, y*HEIGHT);
    }
    G_wait_key();
}