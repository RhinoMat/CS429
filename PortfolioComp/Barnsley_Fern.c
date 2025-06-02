#include "FPToolkit.c"
#define WIDTH 400
#define HEIGHT 400

double x = 0.0;
double y = 0.0;

// Transform functions
void translate(double dx, double dy) {
    x += dx;
    y += dy;
}

void scale(double sx, double sy) {
    x *= sx;
    y *= sy;
}

void rotate(double theta) {
    double radians = theta * M_PI / 180.0;
    double c = cos(radians);
    double s = sin(radians);
    double temp = x * c - y * s;
    y = x * s + y * c;
    x = temp;
}

// Barnsley Fern step using only scale, rotate, translate
void fern(double r_f) {
    if (r_f < 0.01) {
        // Stem: xn = 0.0; yn = 0.16*y;
        scale(0.0, 0.16);
    } else if (r_f < 0.86) {
        // Main leaflets: xn = 0.85*x + 0.04*y; yn = -0.04*x + 0.85*y + 1.6;
        scale(0.85, 0.85);
        rotate(2.6926); // atan2(-0.04, 0.85) in degrees
        translate(0.0, 1.6);
    } else if (r_f < 0.93) {
        // Left leaflets: xn = 0.20*x - 0.26*y; yn = 0.23*x + 0.22*y + 1.6;
        scale(0.2, 0.23);
        rotate(-52.125); // atan2(-0.26, 0.20) in degrees
        translate(0.0, 1.6);
    } else {
        // Right leaflets: xn = -0.15*x + 0.28*y; yn = 0.26*x + 0.24*y + 0.44;
        scale(-0.15, 0.26);
        rotate(61.9275); // atan2(0.28, -0.15) in degrees
        translate(0.0, 0.44);
    }
}

int main() {
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();
    G_rgb(0.0, 1.0, 0.0); // Green fern

    for (int k = 0; k < 200000; k++) {
        double r_f = drand48();
        fern(r_f);
        double plot_x = (x + 2.1820) / (2.6558 + 2.1820) * WIDTH;
        plot_x = WIDTH - plot_x;
        double plot_y = (y / 9.9983 * HEIGHT);
        G_point(plot_x, plot_y);
    }

    G_save_to_bmp_file("FERN.bmp");
}