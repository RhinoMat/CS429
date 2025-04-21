#include "FPToolkit.c"
typedef struct Production
{
char var;
char axiom[100];
char rule[100];
} Production;
Production prd[10];
int rule_num = 0;
char u[1000000], v[1000000];
double angle, gangle, flen;
int depth;
double sheight = 800;
double swidth = 800;
/*
//  plant requires a global stack to be implemented because 
//  [ means put turtle's current location and angular 
//  direction on the stack, and ] means pop info from stack and 
//  position the turtle according to the location and angular 
//  information popped.
*/
void square_wave()
{
  gangle = 90; // initial angle
  angle = 90;  // angle change for '+' and '-'
  // flen = 50 ;  // how far a forward movement goes, determined by autoplacer now
  rule_num = 0;
  strcpy(prd[rule_num].axiom,"A");
  rule_num++;
  prd[rule_num].var = 'A';
  strcpy(prd[rule_num].rule,"f-f-B");
  rule_num++;
  prd[rule_num].var = 'B';
  strcpy(prd[rule_num].rule,"f+f+A");
  rule_num++;
}
void print_string(char *u)
{
  int k;
  k = 0;
  while(u[k] != '\0') {
    printf("%c",u[k]);
    k++;
  }
  printf("\n");
}
int find_rule(char s)
{
  int k;
  for(k=1;k<rule_num;k++) {
    if(prd[k].var == s) { return k; }
  }
  return -1;
}
void string_builder()
{
  int k, c, loc;
  // build array u
  u[0] = '\0';
  strcat(u,prd[0].axiom);
  print_string(u);
  // recur depth times to build string
  for(c=0;c<depth;c++) {
    v[0] = '\0';
    k = 0;
    while(u[k] != '\0') {
      // if symbol is a variable
      loc = find_rule(u[k]);
      if(loc != -1) {
        strcat(v,prd[loc].rule);
      }
      // if symbol is not a variable
      else {
        char temp[2];
        temp[0] = u[k];  temp[1] = '\0';
        strcat(v,temp);
      }
      k++;
    }
    strcpy(u,v);
    print_string(u);
    printf("\n");
  }
}
void autoplacer(int swidth, int sheight, double *p)
{
// Estimate the total length of the string based on depth
int total_moves = 1; // Start with the axiom
for (int i = 0; i < depth; i++) {
  total_moves *= 2;//4; // Each rule expands by approximately 4 times
}

// Calculate the maximum possible forward length
double max_length = (swidth < sheight ? swidth : sheight) / 2.0;
*p = max_length / total_moves; // Divide by total moves to fit within the screen
}
void string_interpreter()  // like an etch-a-sketch
{
  G_init_graphics(swidth, sheight); // Initialize graphics window
  G_rgb(0, 0, 0);                   // Set background color to black
  G_clear();                        // Clear the screen
  G_rgb(0, 1, 0);                   // Set drawing color to green

  double x = swidth / 2;            // Start position (center of the screen)
  double y = sheight / 2;
  double dx, dy;

  for (int i = 0; u[i] != '\0'; i++) {
    char symbol = u[i];
    if (symbol == 'f' || symbol == 'F') {
      // Move forward and draw a line
      dx = flen * cos(gangle * M_PI / 180.0);
      dy = flen * sin(gangle * M_PI / 180.0);
      G_line(x, y, x + dx, y + dy);
      x += dx;
      y += dy;
    } else if (symbol == '+') {
      // Turn left by the angle
      gangle += angle;
    } else if (symbol == '-') {
      // Turn right by the angle
      gangle -= angle;
    }
  }

  G_wait_key(); // Wait for a key press before closing
}
int main()
{
  printf("Please specify the level of depth for the l-system: ");
  scanf("%d",&depth);
  square_wave();
  // plant();
  autoplacer(swidth, sheight, &flen);
  string_builder();
  string_interpreter();
}