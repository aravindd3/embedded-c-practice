//In bare-metal firmware, your code must actively and continuously read the input register
//of a GPIO pin to see if a physical button has changed state. This is called hardware polling
#include<stdio.h>
#include<stdint.h>

uint32_t data=0x00000000;
#define SIMULATED_PORT_1_INPUT (*(volatile uint32_t*)(&data))
int main()
{
    int counter=0;
    printf("System Boot, polling for button press on pin 3...\n");
    while((SIMULATED_PORT_1_INPUT & (1<<3)) ==0)
    {
        //To prevent your Windows PC from freezing in an infinite loop, 
        //our simulation will include a counter that artificially "presses" the button (flips the bit) after 5 loops.
        if(counter == 5)
        {
            SIMULATED_PORT_1_INPUT ^= (1<<3);
            printf("Pin 3 is HIGH...\n");
        }
        else
        {
            printf("Pin 3 is still LOW...\n");
            counter++;
        }
    }
    printf("Success! button was pressed at pin 3, executing the next command..");
}