#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//http://www.uobabylon.edu.iq/eprints/publication_2_22893_6215.pdf

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //get general line equation
  int A = y1 - y0;
  int B = -1 * (x1-x0);

  //get which quadrant we are in
  int oct;
  if ((y1 > y0 && x1 > x0) || (y1 < y0 && x1 < x0)) {
    oct = 1;
    //swap (x0,y0) and (x1,y1) if (x1,y1) isn't above
    if (y1 < y0) {
      int temp = y1;
      y1 = y0;
      y0 = temp;
      temp = x1;
      x1 = x0;
      x0 = x1;
    }
  }


  int x = x0;
  int y = y0;

  int d;

  //octant 1
  d = 2*A + B;
  while (x<=x1) {
    plot(s,c,x,y);
    if (d>0) {
      y ++;
      d += 2*B;
    }
    x ++;
    d += 2*A;
  }

  //octant 2
  d = A + 2*B;
  while (y<=y1) {
    plot(s,c,x,y);
    if (d<0) {
      x ++;
      d += 2*A;
    }
    y++;
    d += 2*B;
  }
}
