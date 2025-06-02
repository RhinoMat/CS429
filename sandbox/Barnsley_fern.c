#include "FPToolkit.c"
#define WIDTH 100
#define HEIGHT 100
double x = 0.0;
double y = 0.0;
double Color[3][4];
/*void colorSetup()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 3; i++)
        {
            double c;
            c = drand48();
            Color[j][i] = c;
        }
    }
}*/
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
void fern(double r_f)
{
    
    double xn = 0.0;
    double yn = 0.0;
    if (r_f < 0.01)
    {
        //G_rgb(Color[0][0], Color[1][0], Color[2][0]);
        //xn = 0.0;
        //yn = 0.16*y;
        scale(0.0, 0.16);
    } else if(r_f < 0.86)
    {
        //G_rgb(Color[0][1], Color[1][1], Color[2][1]);
        //xn = 0.85*x+0.04*y;
        //yn = -0.04*x+0.85*y+1.6;
        scale(0.85, 0.85);
        translate(0.04, 1.6);
    } else if (r_f < 0.93) {
        //G_rgb(Color[0][2], Color[1][2], Color[2][2]);
        //xn = 0.2*x-0.26*y;
        //yn = 0.23*x+0.22*y+1.6;
        scale(0.2, 0.23);
        rotate(-13.0);
        translate(0.0, 1.6);
    }
    else
    {
        //G_rgb(Color[0][3], Color[1][3], Color[2][3]);
        //xn = -0.15*x+0.28*y;
        //yn = 0.26*x+0.24*y+0.44;
        scale(-0.15, 0.26);
        rotate(13.0);
        translate(0.0, 0.44);
    }
    //x=xn;
    //y=yn;
}
int main()
{
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    G_rgb(1.0, 0.0, 0.0);
    //colorSetup();
    for (int k = 0; k < 200000; k++)
    {
        double r_f;
        r_f = drand48();
        fern(r_f);
        //scale(0.75, 0.75);
        //rotate(180);
        //translate(50, 0);
        G_point(x*WIDTH, y*HEIGHT);
    }
    G_wait_key();
    G_save_to_bmp_file("FERN.bmp");
}