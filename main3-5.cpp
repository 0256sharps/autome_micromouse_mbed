#include "mbed.h"

DigitalOut LED_1(D10);
DigitalOut LED_2(D12);

Ticker timer;

void L_chika(){
    LED_1 = !LED_1;
    LED_2 = !LED_2;
}

int main()
{
    LED_1 = 1;
    LED_2 = 0;

    timer.attach(&L_chika, 0.5);
}
