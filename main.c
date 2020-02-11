#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  printf("hi\n");
  clear_screen(s);
  // int i=0;
  // for (i=0;i<150;i++) {
  //   plot(s,c,i,0);
  // }
  printf("hi!\n");

  int left_x = 20;
  int bot_y = 0;

  while (bot_y+100 < YRES) {

    //body
    //brown
    c.red = 139;
    c.green = 69;
    c.blue = 19;
    draw_line(left_x,bot_y,left_x+300,bot_y,s,c);
    draw_line(left_x,bot_y,left_x,bot_y+100,s,c);
    draw_line(left_x+120,bot_y,left_x+120,bot_y+100,s,c);
    draw_line(left_x+120,bot_y+60,left_x+300,bot_y+60,s,c);
    draw_line(left_x+300,bot_y,left_x+300,bot_y+60,s,c);
    //ears
    draw_line(left_x,bot_y+100,left_x+20,bot_y+80,s,c);
    draw_line(left_x+120,bot_y+100,left_x+100,bot_y+80,s,c);
    //top of head
    draw_line(left_x+20,bot_y+80,left_x+100,bot_y+80,s,c);
    //whiskers
    c.red = 255;
    c.green = 255;
    c.blue = 255;
    draw_line(left_x+85,bot_y+40,left_x+135,bot_y+40,s,c);
    draw_line(left_x+90,bot_y+50,left_x+130,bot_y+60,s,c);
    draw_line(left_x+90,bot_y+30,left_x+130,bot_y+20,s,c);
    draw_line(left_x-15,bot_y+40,left_x+35,bot_y+40,s,c);
    draw_line(left_x-10,bot_y+60,left_x+30,bot_y+50,s,c);
    draw_line(left_x-10,bot_y+20,left_x+30,bot_y+30,s,c);
    //eyes
    //sky blue
    c.red = 135;
    c.green = 206;
    c.blue = 250;
    draw_line(left_x+25,bot_y+65,left_x+35,bot_y+65,s,c);
    draw_line(left_x+85,bot_y+65,left_x+95,bot_y+65,s,c);

    bot_y+= 110;
  }


  //MR. DW IMAGE
  // c.red = 0;
  // c.green = 255;
  // c.blue = 0;
  // //octants 1 and 5
  //   draw_line(0, 0, XRES-1, YRES-1, s, c);
  //   draw_line(0, 0, XRES-1, YRES / 2, s, c);
  //   draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c);
  //
  //   //octants 8 and 4
  //   c.blue = 255;
  //   draw_line(0, YRES-1, XRES-1, 0, s, c);
  //   draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
  //   draw_line(XRES-1, 0, 0, YRES/2, s, c);
  //
  //   //octants 2 and 6
  //   c.red = 255;
  //   c.green = 0;
  //   c.blue = 0;
  //   draw_line(0, 0, XRES/2, YRES-1, s, c);
  //   draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);
  //
  //   //octants 7 and 3
  //   c.blue = 255;
  //   draw_line(0, YRES-1, XRES/2, 0, s, c);
  //   draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);
  //
  //   //horizontal and vertical
  //   c.blue = 0;
  //   c.green = 255;
  //   draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
  //   draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);

  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
  return 0;
}
