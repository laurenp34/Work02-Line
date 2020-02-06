#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  printf("hi!\n");
  //get general line equation variables
  int A = y1-y0;
  int B = -(x1-x0);

  //decide which octant line is in

  int x = x0;
  int y = y0;

  //octant 1:
  int d = (2*A) + B;
  while (x <= x1) {
    printf("current point: (%d, %d)\n",x,y);
    plot(s,c,x,y);
    printf("plotted: %d, %d\n", x, y);
    if (d>0) {
      y ++;
      d += (2*B);
    }
    x ++;
    d += (2*A);
  }
}
