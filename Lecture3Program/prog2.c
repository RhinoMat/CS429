#include "FPToolkit.c"
double swidth = 800, sheight = 800;
//swidth = 800;
//sheight = 800;
int main()
{    
    double p[2];
    double q[2];
    G_init_graphics(swidth, sheight);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    G_rgb(1,0,0);
    G_wait_click(p);
    G_fill_circle(p[0],p[1],2);
    G_wait_click(q);
    G_fill_circle(q[0],q[1],2);   
    G_rgb(0,1,0.5);
    G_line(p[0],p[1], q[0],q[1]);
    G_wait_key();
}
int my_line(double line1x, double line1y, double line2x, double line2y)
{
    if (line1x > swidth || line1y > sheight || line2x > swidth || line2y > sheight) return 0;
    if (line1x < 0 || line1y < 0 || line2x < 0 || line2y < 0) return 0;
    double y0 = line1y;
    double x0 = line1x;
    double y1 = line2y;
    double x1 = line2x;
    if (x0 == x1)
    {
        if (y0 > y1)
        {
            double temp = y0;
            y0 = y1;
            y1 = temp;
        }
        for (double y = y0; y <= y1; y += 0.1) {
            G_point(x0, y);
        }
        return 1;
    }
    if (x1 < x0)
    {
        double tempx;
        tempx = x0;
        x0 = x1;
        x1 = tempx;
        double tempy;
        tempy = y0;
        y0 = y1;
        y1 = tempy;
    }
    double slope = (y1-y0)/(x1-x0);
    double yinter = y0 - slope*x0;
    if (fabs(slope) <= 1) {
        // Iterate over x-coordinates
        if (x0 > x1) {
            double temp = x0;
            x0 = x1;
            x1 = temp;
            temp = y0;
            y0 = y1;
            y1 = temp;
        }
        for (double x = x0; x <= x1; x += 0.1) {
            double y = slope * x + yinter;
            G_point(x, y);
        }
    } else {
        // Iterate over y-coordinates for steep lines
        if (y0 > y1) {
            double temp = x0;
            x0 = x1;
            x1 = temp;
            temp = y0;
            y0 = y1;
            y1 = temp;
        }
        for (double y = y0; y <= y1; y += 0.1) {
            double x = (y - yinter) / slope;
            G_point(x, y);
        }
    }
    return 1;
}