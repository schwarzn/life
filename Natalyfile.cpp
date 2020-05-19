#include "TXLib.h"
#include "WalleLib.h"

int main ()
{
    txCreateWindow(1550, 900);

    draw_star(200 , 100, 0.9, RGB(255,255,51), RGB(255,255,51), 20,  0,  1,  0, 0);
    draw_ufo(200 , 280, 0.8, TX_BLUE, RGB (51,51,153), -35,  0,  1,  1,  1);
    draw_boot(200 , 410,   1, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 0,  1,  1,  1);
    draw_robot(200 , 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 0,  1,  1,  0);
    draw_eva(400,  750, 0.7, TX_WHITE, -1,  1, 1,  0,  0, -1);
    return 0;
}

