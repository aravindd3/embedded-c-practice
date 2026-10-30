//In the OOP world, you group related variables into objects. In bare-metal C,
//we use structs to map blocks of physical silicon.
//A microcontroller peripheral (like GPIO Port A) is never just one register.
// It is a cluster of registers (Mode,Output type,Output Speed,Pull up/Pull down, Input Data, Output Data) 
//sitting right next to each other in physical memory, exactly 4 bytes apart.
//Instead of writing dozens of separate #define macros for every single address, 
//we write one struct that perfectly mirrors the hardware layout
#include<stdio.h>
#include<stdint.h>

typedef struct
{
    volatile uint32_t MODE;
    volatile uint32_t OTYPE;
    volatile uint32_t OSPEED;
    volatile uint32_t PULLUPDOWN;
    volatile uint32_t ID;
    volatile uint32_t OD;
}GPIO_REGS;

uint32_t simulated_silicon_block[6]={0,0,0,0,0,0};
#define SIMULATED_PORT_1 (*(GPIO_REGS*)(simulated_silicon_block))
int main()
{
    SIMULATED_PORT_1.MODE=0X00005555;
    SIMULATED_PORT_1.OSPEED=0X01010101;
    SIMULATED_PORT_1.ID ^= (1<<1) | (1<<3);
    printf("MODE  (Index 0): 0x%08X\n", simulated_silicon_block[0]);
    printf("OSPEED (Index 2): 0x%08X\n", simulated_silicon_block[2]);
    printf("ID  (Index 5): 0x%08X\n", simulated_silicon_block[4]);
}