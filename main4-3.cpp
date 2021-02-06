#include "mbed.h"

DigitalOut M_A(D4);
PwmOut PWM_A(D5);
DigitalOut M_B(D7);
PwmOut PWM_B(D6);
DigitalOut LED_1(D10);
DigitalOut LED_2(D12);

float val_PA = 0.5; //速度0~1を格納する変数（LTの機体では0.5前後がおすすめ）
float val_PB = 0.5; //速度0~1を格納する変数（LTの機体では0.5前後がおすすめ）
bool val_MA = 1;    //0か1は配線によって変わる
bool val_MB = 1;    //0か1は配線によって変わる
bool LED_A = 1;
bool LED_B = 1;

int main(){
    while(1){
        //モータA
        M_A = val_MA;
        PWM_A = val_PA;

        //モータB
        M_B = val_MB;
        PWM_B = val_PB;

        //デバッグ用LED（右・左旋回で片方光り，直進で両方光る）
        LED_1 = LED_A;
        LED_2 = LED_B;

        wait(1);
    }
}
