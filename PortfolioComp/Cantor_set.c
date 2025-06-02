#include "FPToolkit.c"
#define WIDTH 800
#define HEIGHT 800

// Draw a single Cantor set segment recursively
void cantor(double x, double y, double length, int depth) {
    if (depth == 0) return;

    // Draw the current segment
    G_fill_rectangle(x, y, length, 10);

    // Recurse for left and right thirds, skipping the middle third
    double next_y = y - 30;
    if (next_y > 0) {
        cantor(x, next_y, length / 3.0, depth - 1);
        cantor(x + 2 * length / 3.0, next_y, length / 3.0, depth - 1);
    }
}

int main() {
    G_init_graphics(WIDTH, HEIGHT);
    G_rgb(1, 1, 1); // White background
    G_clear();
    G_rgb(0, 0, 0); // Black for Cantor set

    // Start drawing from the top
    cantor(50, HEIGHT - 40, WIDTH - 100, 10);

    G_save_to_bmp_file("CANTOR.bmp");
    G_wait_key();
}