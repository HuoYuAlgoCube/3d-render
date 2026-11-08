#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>

void setW(int W);
void setH(int H);
void setBuf(uint32_t* buf);

void putPixel(int x,int y,uint32_t color);

#endif
