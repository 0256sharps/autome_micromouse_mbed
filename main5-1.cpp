#include "mbed.h"

Serial pc(USBTX, USBRX);

AnalogIn PR_1(A0);  //A0ピンを「PR_1」という名前のアナログ入力（AnalogIn）ピンに設定する
AnalogIn PR_2(A1);  //A1ピンを「PR_2」という名前のアナログ入力（AnalogIn）ピンに設定する

int valR = 0;   //A0ピンで受け取った値を格納する変数
int valL = 0;   //A1ピンで受け取った値を格納する変数

int main(){
    while(1){
        valR = float(PR_1.read()) * 1000;  //A0ピンの値を読み取って1000倍する
        valL = float(PR_2.read()) * 1000;  //A1ピンの値を読み取って1000倍する

        pc.printf("valL: %8.3f, valR: %8.3f\r\n", valR, valL);    //読み取った結果を表示する
    }
}
