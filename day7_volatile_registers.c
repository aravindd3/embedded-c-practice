#include<stdio.h>
#include<stdint.h>
//There are predefined hardware registers we could use rather than using main memory to store the address of peripherals.
//If you create a pointer variable (e.g., volatile uint32_t *port_a_ptr = ...),
//that pointer itself is a variable that consumes 4 bytes of RAM just to store the address

// A #define macro consumes absolutely zero RAM. The C preprocessor simply text-replaces SIMULATED_GPIO_PORT_A with the
// raw memory address before the code even compiles, baking the address directly into the CPU's assembly instructions.

#define SIMULATED_GPIO_PORT1 (*(volatile uint32_t*)(&data))

// we dereferenced the variable here so that we could read/write data into this address.
int main()
{
    // THIS IS DATA AT A MEMORY LOCATION
    uint32_t data=0x00000000;
    //now this data is in one of the hardware registers of the microcontroller.
    SIMULATED_GPIO_PORT1=0x000000FF;
    //WE CHANGED THE DATA FROM 00 TO FF.
    printf("Hardware State after overwrite: 0x%08x\n",SIMULATED_GPIO_PORT1);

    // IF WE HAVE CONNECTED 8 LEDS ON PORT 1 AND WANT TO TOGGLE 3 LEDS AT 2,4,6 PINS,
    SIMULATED_GPIO_PORT1 ^= (1<<2) | (1<<4) | (1<<6);
    printf("Hardware state after toggling led at pins 2,4,6 at port 1: 0x%08x",SIMULATED_GPIO_PORT1);
}