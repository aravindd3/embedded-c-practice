#include<stdio.h>
#include<stdint.h>
int main()
{
    uint8_t  dat=0b00010001;
    //have to make the 3rd bit 1
    dat=dat | (1<<3);
    // clear the 5th bit
    dat=dat & ~(1<<5);
    printf("result in hexadecimal: 0x%02X\n",dat);
    printf("result in decimal: %u\n",dat);
    return 0;
}
