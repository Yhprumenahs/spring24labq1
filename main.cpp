#include "mbed.h"
#include <cstdio>


 InterruptIn buttn(PC_13);

 volatile int myflag = 0;

 void buttn_fall(){
     myflag = 1;
    
 }

// main() runs in its own thread in the OS
int main()
{
    printf("this is mbed os v%d \r\n", MBED_VERSION);
    //turns on and prints what mbed version the mbed is
    buttn.fall(&buttn_fall);
    while (true) {
        if(myflag == 1){
            printf("button pressed!!\r\n");
            //button is pressed and 'button pressed' appears on coolterm
            myflag = 0;
            //when button is not pressed the flag resets to zero and nothings is printed until the button is pressed again
        }

    }
}

