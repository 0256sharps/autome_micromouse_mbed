#include "mbed.h"

PwmOut LED(D10); //D10ピンを「LED」という名前のPWM出力（PwmOut）ピンに設定する

int main()
{
    while(1){
        LED = 0.5;   //「LED」ピンの出力のduty比を50％に設定する
        wait(0.5);
    }
}
