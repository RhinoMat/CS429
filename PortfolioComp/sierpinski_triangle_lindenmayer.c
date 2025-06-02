/*
    Sierpinski Triangle fractal generator for the final portfolio project.
    Utilizes an L-system to generate the fractal.
    Fractal Type: L-system
*/
#include "FPToolkit.c"
#define TRUE 1
#define FALSE 0
char u[1000000];
char temp[1000000];
char s[10];
char w[10][1000];
int n = 0; // n = # rules in Grammar
void function (int depth)
{
  if (depth == 0)
    return;
  int flag = FALSE;
  temp[0] = '\0';
  char dumb[2];
  for (int i = 0; i < strlen(u); ++i)
  {
    for (int j = 0; j < strlen(s); ++j)
    {
      if (u[i] == s[j])
      {
        strcat(temp, w[j]);
        flag = TRUE;
        break;
      }
      else
      {
        flag = FALSE;
      }
    }
    if (flag == FALSE)
    {
      dumb[0] = u[i];
      dumb[1] = '\0';
      strcat(temp, dumb);
    }
  }
  strcpy(u, temp);
  function(depth - 1);
}
void color(int i)
{
  switch(i % 3) 
  {
    case 0:
      G_rgb(1, 0, 0);
      break;
    case 1:
      G_rgb(0, 0.5, 0.15);
      break;
    case 2:
      G_rgb(1, 0.84, 0);
      break;
    case 3:
      G_rgb(1, 1, 0);
      break;
    default:
      break;
  }
}
int main() {
  int swidth, sheight;
  double deg = 58;
  double unit = 10;
  double turtle[2];
  double potential[2];
  double hold[2];
  double initx = 50, inity = 50;
  double x, y;
  int flag = FALSE;
  swidth = 800;
  sheight = 700;
 strcpy(u, "A");
 n = 2;
 s[0] = 'A';
 strcpy(w[0], "B-A-B");
 s[1] = 'B';
 strcpy(w[1], "A+B+A");
  function(6);
  G_init_graphics(swidth, sheight); // interactive graphics
  for(double j = 0; j < 10; j-= 0.1) {
    // unit -= 0.2;
    deg += 2;
    G_rgb(0, 0, 0);
    G_clear();
    // INITIALIZE TURTLE
    turtle[0] = initx;
    turtle[1] = inity;
    potential[0] = turtle[0] + unit;
    potential[1] = turtle[1];
    // COLOR OF TURTLE!!
    G_rgb(0, 1, 0);
    G_fill_circle(turtle[0], turtle[1], 1);
    G_wait_key();
    // LETS START MOVING
    double c, s;
    double theta;
    double temp;
    theta = deg * M_PI / 180;
    c = cos(theta);
    s = sin(theta);
    for (int i = 0; i < strlen(u); ++i) {
      color(i);
      if (u[i] == '+') { //+
        potential[0] = potential[0] - turtle[0];
        potential[1] = potential[1] - turtle[1];
        hold[0] = (potential[0] * c - potential[1] * s);
        hold[1] = (potential[0] * s + potential[1] * c);
        potential[0] = hold[0] + turtle[0];
        potential[1] = hold[1] + turtle[1];
      } else if (u[i] == '-') { //+
        potential[0] = potential[0] - turtle[0];
        potential[1] = potential[1] - turtle[1];
        hold[0] = (potential[0] * c) + (potential[1] * s);
        hold[1] = -(potential[0] * s) + (potential[1] * c);
        potential[0] = hold[0] + turtle[0];
        potential[1] = hold[1] + turtle[1];
      }
      else if (u[i] <= 'Z' && u[i] >= 'A') { // uppercase letter
        // G_wait_key();
        G_line(turtle[0], turtle[1], potential[0], potential[1]);
        hold[0] = potential[0] - turtle[0];
        hold[1] = potential[1] - turtle[1];
        turtle[0] = potential[0];
        turtle[1] = potential[1];
        potential[0] += hold[0];
        potential[1] += hold[1];
        G_fill_circle(turtle[0], turtle[1], 1);
      } else {
      continue;
    }
  }
  int key;
  key = G_wait_key();
  }
  int key;
  key = G_wait_key();
}