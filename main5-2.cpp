#include "mbed.h"

Serial pc(USBTX, USBRX);

AnalogIn PR_1(A0);
AnalogIn PR_2(A1);

Ticker timer;

int valR = 0;
int valL = 0;

void sensor_read(){
    valR = float(PR_1.read()) * 1000;  //A0ピンの値を読み取って1000倍する
    valL = float(PR_2.read()) * 1000;  //A1ピンの値を読み取って1000倍する

    pc.printf("valL: %8.3f, valR: %8.3f\r\n", valL, valR);
}

int main()
{
    timer.attach(&sensor_read, 0.01);
}
