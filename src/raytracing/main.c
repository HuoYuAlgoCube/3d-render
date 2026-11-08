#include "fenster.h"
#include <stdint.h>
#include <stdlib.h>
#include "render.h"

#define W 800
#define H 600
#define TITLE "Render 3D"
#define FPS 1000.0 / 60.0

int main(void){
    uint32_t buf[W*H];
    setBuf(buf);
    setW(W);
    setH(H);
    struct fenster f = {
        .buf = buf,
        .title = TITLE,
        .width = W,
        .height = H
    };
    if (fenster_open(&f) != 0)return -1;

    while (fenster_loop(&f) == 0){
        for (int i=0;i<W*H;i++){
            buf[i] = 0x222222;
        }
        for (int i=0;i<W;i++){
            putPixel(i,100,0xFF0000);
        }
        fenster_sleep(FPS);
    }
    fenster_close(&f);
    return 0;
}
