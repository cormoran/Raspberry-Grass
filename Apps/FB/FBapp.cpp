#include”../../Library/Glcd.h"
#include”../../Library/FrameBuffer/framebuffer.h"
#include<unistd.h>
#include<iostream>
#include<cstdio>
#include<bcm2835.h>

#define SW_g RPI_BPLUS_GPIO_J8_03//green 
#define SW_b1 RPI_BPLUS_GPIO_J8_05 //blue1
#define SW_b2 RPI_BPLUS_GPIO_J8_07 //blue2
#define SW_w1 RPI_BPLUS_GPIO_J8_11 //white1
#define SW_w2 RPI_BPLUS_GPIO_J8_12 //white2

using namespace std;

int end()
{
  printf("Green Switch was pressed !");
  exit(0);
}

//セマフォ付きのフレームバッファ表示クラス
int main()
{
  Glcd lcd;
  gl_lcd::framebuffer fb;
  bcm2835_init();

  while(1)
    {
      if(!bcm2835_gpio_lev(SW_g))end();
      lcd.SendData_RGB565(fb.GetFrameAddress(),128*128*2);
      usleep(50000);//50ms
    }
  return 0;


}
