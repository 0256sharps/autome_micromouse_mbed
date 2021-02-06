#include "mbed.h"

DigitalOut LED(D10);

Ticker timer;   //Tickerの宣言

//割り込み処理関数
void flash(){
    LED = !LED;
}

int main()
{
    LED = 1;                    //「LED」ピンの出力を3.3V（HIGH）にする

    timer.attach(&flash, 0.5);  //0.5秒毎に関数「flash」を割込みする（引数は(割込み処理関数のポインタ,割込み周期[s])）
}
