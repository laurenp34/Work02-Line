#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

// void switch(int x0, int y0, int x1, int y1) {
//   int temp = y1;
//   y1 = y0;
//   y0 = temp;
//   temp = x1;
//   x1 = x0;
//   x0 = temp;
// }

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  //get which quadrant we are in
  int oct=0;
  int dx = x1-x0;
  int dy = y1-y0;

  //vertical line:
  if (x1 == x0) {
    if (y1 > y0) {
      while (y0 <= y1) {
        plot(s,c,x1,y0);
        y0++;
      }
    } else {
      while (y1 <= y0) {
        plot(s,c,x1,y1);
        y1++;
      }
    }

  }

  if ((dx>0 && dy>0 && dx>=dy) || (dx<0 && dy<0 && dx<=dy)) {
    oct = 1;
    //swap (x0,y0) and (x1,y1) if (x1,y1) isn't above
    if (y1 < y0) {
      printf("switchng 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
      int temp = y1;
      y1 = y0;
      y0 = temp;
      temp = x1;
      x1 = x0;
      x0 = temp;// switch(x0,y0,x1,y1);
      printf("new 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
    }
  }
  else if ((dx>0 && dy>0 && dx<=dy) || (dx<0 && dy<0 && dx>=dy)) {
    oct = 2;
    if (y1 < y0) {
      printf("switchng 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
      int temp = y1;
      y1 = y0;
      y0 = temp;
      temp = x1;
      x1 = x0;
      x0 = temp;
      // switch(x0,y0,x1,y1);
      printf("new 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);

    }
  }
  else if ((dx<0 && dy>0 && -1*dx <= dy) || (dx>0 && dy<0 && -1*dy >= dx)) {
    oct = 3;
    if (y1 < y0) {
      printf("switchng 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
      int temp = y1;
      y1 = y0;
      y0 = temp;
      temp = x1;
      x1 = x0;
      x0 = temp;
      // switch(x0,y0,x1,y1);
      printf("new 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
    }
  }
  else {
    oct = 4;
    if (x1 > x0) {
      printf("switchng 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
      int temp = y1;
      y1 = y0;
      y0 = temp;
      temp = x1;
      x1 = x0;
      x0 = temp;
      // switch(x0,y0,x1,y1);
      printf("new 0: (%d,%d)\t1: (%d,%d)\n",x0,y0,x1,y1);
    }
  }
  //oct = 4;
  printf("OCTANT: %d\n",oct);


  int x = x0;
  int y = y0;

  //get general line equation
  int A = y1 - y0;
  int B = -1 * (x1-x0);

  int d;

  //octant 1 + 5(0 < slope < 1)
  if (oct == 1){
    d = 2*A + B;
    while (x<=x1) {
      //printf("Plotting: (%d,%d)\n",x,y);
      //printf("d: %d\tPlotting: (%d,%d)\n",d,x,y);
      plot(s,c,x,y);
      if (d>0) {
        y ++;
        d += 2*B;
      }
      x ++;
      d += 2*A;
    }
  }

  //octant 2 + 6(1 < slope < infinity)
  if (oct == 2){
    //printf("plotting oct2 line\n");
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

  //octant 3 + 7
  if (oct == 3) {
    //printf("plotting oct3 line\n");
    d = 2*B - A;
    while (y <= y1) {
      //printf("d: %d\tPlotting: (%d,%d)\n",d,x,y);
      plot(s,c,x,y);
      if (d>0) {
        x --;
        d -= 2*A;
      }
      y ++;
      d += 2*B;
    }
  }

  //octant 4 + 8
  if (oct ==4){
    d = B - 2*A;
    while (x >= x1) {
      plot(s,c,x,y);
      if (d < 0) {
        y ++;
        d += 2*B;
      }
      x --;
      d -= 2*A;
    }
  }
}
