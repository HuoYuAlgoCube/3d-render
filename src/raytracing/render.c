#include <stdint.h>
#include <render.h>
#include <stdlib.h>
#include "graphics.h"

static uint32_t* buf = NULL;
static Rect C = {.w = 0,.h = 0,.x = 0,.y = 0},V = {.w = 0,.h = 0,.x = 0,.y = 0};

void setCanvasW(int w){
    C.w = w;
}
void setCanvasH(int h){
    C.h = h;
}
void setBuf(uint32_t* buffer){
    buf = buffer;
}
static int check(){
    return C.w >= 0 && C.h >= 0 &&
           V.w >= 0 && V.h >= 0 &&
           buf != NULL ? 1 : 0;
}

void putPixel(int x,int y,uint32_t color){
    if (check() != 1)return;
    if (x < 0 || y < 0 || x >= C.w || y >= C.h)return;
    buf[y*C.w+x] = color;
}
