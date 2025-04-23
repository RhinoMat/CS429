#include "FPToolkit.c"

typedef struct Production
{

  char var ;
  char axiom[100] ;
  char rule[100] ;

} Production ;


Production prd[10] ;
int rule_num = 0 ;

char u[1000000], v[1000000] ;
double angle, gangle, flen ;
int depth ;

/*
//  plant requires a global stack to be implemented because 
//  [ means put turtle's current location and angular 
//  direction on the stack, and ] means pop info from stack and 
//  position the turtle according to the location and angular 
//  information popped.

*/
void square_wave()
{

  gangle = 90 ; // initial angle
  angle = 90 ;  // angle change for '+' and '-'
  // flen = 50 ;  // how far a forward movement goes, determined by autoplacer now
  
  rule_num = 0 ;

  strcpy(prd[rule_num].axiom,"A") ;
  rule_num++ ;

  prd[rule_num].var = 'A' ;
  strcpy(prd[rule_num].rule,"f-f-B") ;
  rule_num++ ;

  prd[rule_num].var = 'B' ;
  strcpy(prd[rule_num].rule,"f+f+A") ;
  rule_num++ ;

}


void print_string(char *u)
{

  int k ;
  k = 0 ;
  while(u[k] != '\0') {
    printf("%c",u[k]) ;
    k++ ;
  }
  printf("\n") ;
}


int find_rule(char s)
{
  int k ;
  for(k=1;k<rule_num;k++) {
    if(prd[k].var == s) { return k ; }
  }
  return -1 ;
}


void string_builder()
{
  int k, c, loc ;
  
  // build array u
  u[0] = '\0' ;
  strcat(u,prd[0].axiom) ;
  print_string(u) ;


  // recur depth times to build string
  
  
  for(c=0;c<depth;c++) {
    v[0] = '\0' ;
    k = 0 ;
    while(u[k] != '\0') {
      
      // if symbol is a variable
      loc = find_rule(u[k]) ;
      if(loc != -1) {
	strcat(v,prd[loc].rule) ;
      }
      
      // if symbol is not a variable
      else {
	char temp[2] ;
	temp[0] = u[k] ;  temp[1] = '\0' ;
	strcat(v,temp) ;
      }
      
      k++ ;
    }
    strcpy(u,v) ;
    print_string(u) ;
    printf("\n") ;
  }
  
}


void autoplacer(int swidth, int sheight, double *p)
{

  // your code goes here!

  double x = 0, y = 0; // Starting position
  double new_x, new_y;
  double current_angle = gangle; // Initial angle
  double min_x = 0, max_x = 0, min_y = 0, max_y = 0;
  int k = 0;

  // Simulate the drawing to find the bounding box
  while (u[k] != '\0') {
    if (u[k] == 'F') {
      new_x = x + cos(current_angle * M_PI / 180.0);
      new_y = y + sin(current_angle * M_PI / 180.0);
      x = new_x;
      y = new_y;

      // Update bounding box
      if (x < min_x) min_x = x;
      if (x > max_x) max_x = x;
      if (y < min_y) min_y = y;
      if (y > max_y) max_y = y;
    } else if (u[k] == '+') {
      current_angle += angle;
    } else if (u[k] == '-') {
      current_angle -= angle;
    }
    k++;
  }

  // Calculate the width and height of the bounding box
  double width = max_x - min_x;
  double height = max_y - min_y;

  // Determine the scaling factor to fit the drawing within the window
  double scale_x = swidth / width;
  double scale_y = sheight / height;

  // Use the smaller scaling factor to maintain aspect ratio
  flen = (scale_x < scale_y ? scale_x : scale_y) * 0.9; // Add a margin

  // Set the starting position to center the drawing
  p[0] = (swidth - (width * flen)) / 2 - (min_x * flen);
  p[1] = (sheight - (height * flen)) / 2 - (min_y * flen);
  
}


void string_interpreter()  // like an etch-a-sketch
{
  double x = 300, y = 300; // Starting position
  double new_x, new_y;
  double current_angle = gangle; // Initial angle
  int k = 0;

  G_init_graphics(600, 600); // Initialize graphics window
  G_rgb(0, 0, 0);            // Set background color to black
  G_clear();                 // Clear the screen
  G_rgb(1, 1, 1);            // Set drawing color to white

  while (u[k] != '\0') {
    if (u[k] == 'F') {
      // Move forward by 10 units
      new_x = x + flen * cos(current_angle * M_PI / 180.0);
      new_y = y + flen * sin(current_angle * M_PI / 180.0);
      G_line(x, y, new_x, new_y);
      x = new_x;
      y = new_y;
    } else if (u[k] == '+') {
      // Turn positively by the angle
      current_angle += angle;
    } else if (u[k] == '-') {
      // Turn negatively by the angle
      current_angle -= angle;
    }
    k++;
  }

  G_wait_key() ;
}



int main()
{

  double start_position[2];

  printf("Please specify the level of depth for the l-system: ") ;
  scanf("%d",&depth) ;
  
  square_wave() ;
  // plant() ;
  
  string_builder() ;
  autoplacer(600, 600, start_position);
  string_interpreter() ;

}
