#include "mbed.h"

DigitalOut LED_1(D10);
DigitalOut LED_2(D12);

int main()
{
    while(1){
        LED_1 = 0;
        LED_2 = 1;
        wait(0.5);
        LED_1 = 1;
        LED_2 = 0;
        wait(0.5);
    }
}
