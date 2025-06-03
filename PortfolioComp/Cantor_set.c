/*
    Cantor Set fractal generator for the final portfolio project.
    Utilizes recursion to generate the fractal.
    Fractal Type: Recursion
    Artistic Addition: give it custom colors and have a flipped version and 
    make it look like a sunny day with the reflection in a still water.
*/
#include "FPToolkit.c"
#define WIDTH 800
#define HEIGHT 600

// Draw a single Cantor set segment recursively
void cantor(double x, double y, double length, int depth) {
    if (depth == 0) return;
    if (depth % 2 == 0)
        G_rgb(1, 0, 1);
    else
        G_rgb(1, 1, 0);
    // Draw the current segment
    G_fill_rectangle(x, y, length, 10);

    // Recurse for left and right thirds, skipping the middle third
    double next_y = y - 30;
    if (next_y > 0) {
        cantor(x, next_y, length / 3.0, depth - 1);
        cantor(x + 2 * length / 3.0, next_y, length / 3.0, depth - 1);
    }
}

void flip_cantor(double x, double y, double length, int depth) {
    if (depth == 0) return;
    if (depth % 2 == 0)
        G_rgb(1, 0, 1);
    else
        G_rgb(1, 1, 0);
    // Draw the current segment
    G_fill_rectangle(x, y, length, 10);

    // Recurse for left and right thirds, skipping the middle third
    double next_y = y + 30;
    if (next_y < HEIGHT) {
        cantor(x, next_y, length / 3.0, depth - 1);
        cantor(x + 2 * length / 3.0, next_y, length / 3.0, depth - 1);
    }
}

int main() {
    G_init_graphics(WIDTH, HEIGHT);
    //G_rgb(1, 1, 1); // White background
    G_rgb(255.0 / 255.0, 151.0 / 255.0, 0.0 / 255.0);
    G_clear();
    G_rgb(173.0/255.0, 216.0/255.0, 230.0/255.0);
    G_fill_rectangle(0, 0, WIDTH, HEIGHT / 2);
    G_rgb(1, 1, 0);
    G_fill_circle(30, 30, 20);
    G_rgb(1, 1, 0);
    G_fill_circle(30, HEIGHT - 30, 20);
    G_rgb(0, 0, 0); // Black for Cantor set

    // Start drawing from the top
    cantor(50, HEIGHT - 100, WIDTH - 100, 6);
    flip_cantor(50, 100, WIDTH - 100, 6);
    G_save_to_bmp_file("CANTOR.bmp");
    //G_wait_key();
}