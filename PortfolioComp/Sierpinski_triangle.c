/*
    Sierpinski Triangle fractal based graphic for the final portfolio project.
    Utilizes recursion to draw the triangle.
    Fractal Type: Recursive
*/
#include "FPToolkit.c"
int main() {
    // Set up the graphics window
    int width = 800;
    int height = 800;
    initwindow(width, height, "Sierpinski Triangle");

    // Set the initial points of the triangle
    Point p1 = {width / 2, 50};
    Point p2 = {50, height - 50};
    Point p3 = {width - 50, height - 50};

    // Draw the Sierpinski triangle
    drawSierpinski(p1, p2, p3, 5); // Change the depth as needed

    // Wait for a key press before closing
    getch();
    closegraph();
    return 0;
}