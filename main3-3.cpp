#include "mbed.h"

DigitalOut LED(D10);

int main()
{
    LED = 1;        //「LED」ピンの出力を3.3V（HIGH）にする
    while(1){
        LED = !LED; //「LED」ピンの出力を，HIGHの場合はLOWに，LOWの場合はHIGHにする
        wait(0.5);
    }
}
