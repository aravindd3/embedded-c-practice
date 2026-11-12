//On an STM32 microcontroller, the MODER(Mode Register) uses two bits for every single physical pin,rather than just one.
// so  pin 0 -> bit 0,1
//     pin 1 -> bit 2,3 
// ..  pin 5 -> bit 10,11
// ..  pin 15 -> bit 30,31
//every port has likely 15 pins like these.
//The manufacturer designed it this way because a pin can be in one of four different states,
// and you need two bits of binary to represent four options:
//00 = Input
//01 = Output
//10 = Alternate Function
//11 = Analog (This is the default state to save power).

#include <stdio.h>
#include <stdint.h>
//RESET AND CLOCK CONTROL REGS
typedef struct{
    volatile uint32_t AHB1ENR;
}RCC_REGS;

typedef struct {
    volatile uint32_t MODER;
} GPIO_REGS;

// Simulating silicon where every pin starts in Analog mode (11)
uint32_t gpio_a_silicon[1] = {0xFFFFFFFF}; 
uint32_t rcc_silicon[1]={0};
#define SIMULATED_GPIOA (*(GPIO_REGS*)(gpio_a_silicon))
#define SIMULATED_RCC (*(RCC_REGS*) (rcc_silicon))
int main() {
    printf("Initial MODER state: 0x%08X\n", SIMULATED_GPIOA.MODER);
    printf("System is Booting...\n");
    SIMULATED_RCC.AHB1ENR |= (1<<0);
// TODO 1: Turn on the clock for GPIO Port A 
    SIMULATED_RCC.AHB1ENR |= (1 << 0);
    
    // TODO 2: Configure Pin 0 as Input (Clear bits 0 and 1)
    SIMULATED_GPIOA.MODER &= ~(3 << 0); // 3 is binary 11

    // TODO 3: Configure Pin 5 as Output (Clear bits 10 and 11, then Set bit 10)
    SIMULATED_GPIOA.MODER &= ~(3 << 10); // Clear Phase
    SIMULATED_GPIOA.MODER |= (1 << 10);  // Set Phase
    

    printf("Final MODER state:   0x%08X\n", SIMULATED_GPIOA.MODER);
    return 0;
}