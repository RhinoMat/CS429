#include "FPToolkit.c"
/*

       Y+
       |
       |    * (y,z)
       |  
<------+--------Z+
   D   |
       |
       |


y'    y
- =  ---
D    D+z

H = D*tan(halfangle) ;

with the x-axis perpendicular to this plane.
*/
#define M 700000
double Wsize = 1000  ; // window size ... choose 600 for repl
double X[M],Y[M],Z[M] ;
double Xplot[M],Yplot[M] ;
int N = 0 ;
int translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}
int rotate_x(double degrees)
// Y[] and Z[] will change but X[] will be unchanged
{
  double radians,c,s,temp ;
  int i ; 
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*Y[i] - s*Z[i] ;
    Z[i] =  s*Y[i] + c*Z[i] ;
    Y[i] = temp ;
  }
}
int rotate_y(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
  }
}
int rotate_z(double degrees)
// X[] and Y[] will change but Z[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] - s*Y[i] ;
    Y[i] =  s*X[i] + c*Y[i] ;
    X[i] = temp ;
  }
}
int project(double observer_distance, double halfangle_degrees)
{
  // student work goes here
  for (int i = 0; i < M; i++)
  {
    Xplot[i] = (X[i] / (observer_distance+Z[i])) * (Wsize / (2*tan(halfangle_degrees))) + (Wsize/2);
    Yplot[i] = (Y[i] / (observer_distance+Z[i])) * (Wsize / (2*tan(halfangle_degrees))) + (Wsize/2);
  }
}
int draw()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }
}
int print_object()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf, %lf)   (%lf, %lf, %lf)\n", 
	   X[i],Y[i],Z[i],  X[i+1],Y[i+1],Z[i+1]) ;
  }
  printf("===============================\n") ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf)   (%lf, %lf)\n", 
	   Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }  
}
int save_line(double xs, double ys, double zs,
	      double xe, double ye, double ze)
{
  // about to add items at slots N and N+1 :
  if (N+1 >= M) {
    printf("full\n") ;
    return 0 ;
  } 
  X[N] = xs ; Y[N] = ys ; Z[N] = zs ; N++ ;
  X[N] = xe ; Y[N] = ye ; Z[N] = ze ; N++ ;
  return 1 ;
}
int build_pyramid()
{
  int n,k ;
  double a,x[100],z[100],yv ;
  N = 0 ; // global
  n = 4 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }
  yv = -1 ;
  for (k = 0; k < n ; k++) {
    save_line(0,2,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
}
int test_pyramid()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;
  build_pyramid() ;
  project(3,45) ;
  draw() ;
  print_object() ;
  G_wait_key() ;
}
int test_pyramid_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;
  build_pyramid() ;
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2);
    //rotate_x(2);
    //rotate_z(2);  
    if (G_wait_key() == 'q') { break ; }
  }
}
int build_hexagon()
{
  int n,k ;
  double a,x[100],z[100],yv ;
  N = 0 ; // global
  n = 6 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }
  yv = -1 ;
  for (k = 0; k < n ; k++) {
    save_line(0,2,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
}
int test_hexagon()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;
  build_hexagon() ;
  project(3,45) ;
  draw() ;
  print_object() ;
  G_wait_key() ;
}
int test_hexagon_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;
  build_hexagon() ;
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2);
    //rotate_x(2);
    //rotate_z(2);  
    if (G_wait_key() == 'q') { break ; }
  }
}
void sierp(double x0, double y0, double x1, double y1, double x2, double y2, int depth)
{
  if (depth <= 0) return;

  // Calculate midpoints of the triangle's edges
  double midpoint1[2] = {(x0 + x1) / 2, (y0 + y1) / 2};
  double midpoint2[2] = {(x1 + x2) / 2, (y1 + y2) / 2};
  double midpoint3[2] = {(x0 + x2) / 2, (y0 + y2) / 2};

  G_rgb(0.0, 1.0, 0.0); 
  G_triangle(midpoint1[0], midpoint1[1], midpoint2[0], midpoint2[1], midpoint3[0], midpoint3[1]);

  sierp(x0, y0, midpoint1[0], midpoint1[1], midpoint3[0], midpoint3[1], depth - 1);
  sierp(midpoint1[0], midpoint1[1], x1, y1, midpoint2[0], midpoint2[1], depth - 1);
  sierp(midpoint3[0], midpoint3[1], midpoint2[0], midpoint2[1], x2, y2, depth - 1);
}
int build_hexagon_with_sierpinski()
{
  int n, k;
  double a, x[100], z[100], yv;
  N = 0; // global
  n = 6;

  for (k = 0; k <= n; k++) {
    a = k * 2 * M_PI / n;
    x[k] = cos(a);
    z[k] = sin(a);
  }

  yv = -1;
  for (k = 0; k < n; k++) {
    save_line(0, 2, 0, x[k], yv, z[k]);
    save_line(x[k], yv, z[k], x[k + 1], yv, z[k + 1]);

    // Generate Sierpinski triangle on each side
    double x0 = x[k], y0 = yv, z0 = z[k];
    double x1 = x[k + 1], y1 = yv, z1 = z[k + 1];
    double x2 = 0, y2 = 2, z2 = 0;

    // Project the vertices to 2D for Sierpinski calculation
    double X0 = (x0 / (3 + z0)) * (Wsize / (2 * tan(45))) + (Wsize / 2);
    double Y0 = (y0 / (3 + z0)) * (Wsize / (2 * tan(45))) + (Wsize / 2);
    double X1 = (x1 / (3 + z1)) * (Wsize / (2 * tan(45))) + (Wsize / 2);
    double Y1 = (y1 / (3 + z1)) * (Wsize / (2 * tan(45))) + (Wsize / 2);
    double X2 = (x2 / (3 + z2)) * (Wsize / (2 * tan(45))) + (Wsize / 2);
    double Y2 = (y2 / (3 + z2)) * (Wsize / (2 * tan(45))) + (Wsize / 2);

    sierp(X0, Y0, X1, Y1, X2, Y2, 3);
  }
}
int test_hexagon_with_sierpinski()
{
  G_init_graphics(Wsize, Wsize);
  G_rgb(0, 0, 0);
  G_clear();
  G_rgb(0, 1, 0);
  build_hexagon_with_sierpinski();
  project(3, 45);
  draw();
  G_wait_key();
}
int test_hexagon_sierpinski_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;
  build_hexagon_with_sierpinski();
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2);
    //rotate_x(2);
    //rotate_z(2);  
    if (G_wait_key() == 'q') { break ; }
  }
}
int main()
{
  // test_pyramid() ;
  //test_pyramid_rotate() ;
  //test_hexagon();
  //test_hexagon_rotate();
  //test_hexagon_with_sierpinski();
  test_hexagon_sierpinski_rotate();
}
