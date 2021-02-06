#include "mbed.h"

DigitalOut LED(D10);  //D10ピンを「LED」という名前のデジタル出力（DigitalOut）ピンに設定する

int main()
{
    while(1){
        LED = 0;    //「LED」ピンの出力を0V（LOW）にする
        wait(1);    //１秒間待つ
        LED = 1;    //「LED」ピンの出力を3.3V（HIGH）にする
        wait(1);    //１秒間待つ
    }
}
