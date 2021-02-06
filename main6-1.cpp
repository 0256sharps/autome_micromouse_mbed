#include "mbed.h"

Serial pc(USBTX, USBRX);    //Serial通信の設定

//各ピンの設定
DigitalOut LED_1(D10);
DigitalOut LED_2(D12);
DigitalOut M_A(D4);
PwmOut PWM_A(D5);
DigitalOut M_B(D7);
PwmOut PWM_B(D6);
AnalogIn PR_1(A0);
AnalogIn PR_2(A1);

Ticker timer;   //タイマ割込みの呼び出し

int MODE = 0;   //走行モードに使用する変数

//関数のプロトタイプ宣言
void sensor_read();
void motor_run(int MODE);

int main()
{
    timer.attach(&sensor_read, 0.01);   //タイマ割込み設定
    while(1){
        motor_run(MODE);
        wait(0.01);
    }
}

//（センサ読み取り＆表示関数）＋（読み取った値から走行モードを返す関数）
void sensor_read(){

    //閾値の設定
    //〇自分で閾値を設定してみよう！
    const float TL = 400.0;
    const float TR = 400.0;

    //センサから受け取った値を格納する変数
    static float valR = 0;
    static float valL = 0;

    valR = float(PR_1.read()) * 1000;  //A0ピンの値を読み取って1000倍する
    valL = float(PR_2.read()) * 1000;  //A1ピンの値を読み取って1000倍する

    pc.printf("valL: %8.3f, valR: %8.3f\r\n", valL, valR);    //読み取った結果を表示する

    //走行モード決定（右白左黒＋L旋回0，右黒左白R旋回1，黒黒or白白直進2）
    //〇空欄に不等号を入れてみよう！
    if(valR > TR && valL < TL){
        MODE = 0;
    } else if(valR < TR && valL > TL){
        MODE = 1;
    } else{
        MODE = 2;
    }
}

void motor_run(int MODE){
    //PWM値を格納する変数
    float val_PA = 0.0;
    float val_PB = 0.0;

    //渡されたモードに応じてモータに出力する
    //〇空欄を埋めてみよう！
    switch(MODE){
        //左旋回
        case 0:
            val_PA = 0.0; val_PB = 1.0;
            M_A = 0;    M_B = 1;    //それぞれの機体に合わせて0か1を入力
            LED_1 = 0;  LED_2 = 1;
            break;

        //右旋回
        case 1:
            val_PA = 1.0; val_PB = 0.0;
            M_A = 1;    M_B = 0;    //それぞれの機体に合わせて0か1を入力
            LED_1 = 1;  LED_2 = 0;
            break;

        //直進
        case 2:
            val_PA = 0.5; val_PB = 0.5;
            M_A = 1;    M_B = 1;    //それぞれの機体に合わせて0か1を入力
            LED_1 = 1;  LED_2 = 1;
            break;
    }
}
