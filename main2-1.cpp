#include "mbed.h"          //mbedを利用するために先頭に入れる

Serial pc(USBTX, USBRX);   //PCとのシリアル通信を行う宣言

int main()
{
    while(1){                           //while(1)で無限ループを作成
        pc.printf("Hello World!\r\n");  //PCに「Hello World!」を表示する
                                        //※\nは改行記号，\rは改行する際にTera Termに表示される位置を揃えるために入れる

        wait(1); //１秒間待つ
    }
}
