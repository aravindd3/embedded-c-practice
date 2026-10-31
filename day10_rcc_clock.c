//Every peripheral on an ARM Cortex microcontroller boots up completely dead.The silicon gates the clock signals 
//to save power, meaning if you try to read or write to a GPIO register before explicitly turning on its clock,
// the CPU will instantly crash and throw a HardFault error.
//To write professional firmware, 
//your initialization sequence must always start at the RCC (Reset and Clock Control) registers.

#include <stdio.h>
#include <stdint.h>
typedef struct {
    volatile uint32_t CR;       // Control Register
    volatile uint32_t CFGR;     // Configuration Register
    volatile uint32_t AHB1ENR;  // AHB1(Advance High Perfomance Bus 1) Peripheral Clock Enable Register
} RCC_REGS;
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
} GPIO_REGS;

uint32_t rcc_silicon[3] = {0, 0, 0};
uint32_t gpio_a_silicon[2] = {0, 0};
#define SIMULATED_RCC   (*(RCC_REGS*)(rcc_silicon))
#define SIMULATED_GPIOA (*(GPIO_REGS*)(gpio_a_silicon))

int main() {
    printf("Booting system... powering up peripherals.\n\n");
    SIMULATED_RCC.AHB1ENR |= (1 << 0);
    SIMULATED_GPIOA.MODER = 0x00005555;
    printf("RCC AHB1ENR (Index 2): 0x%08X\n", rcc_silicon[2]);
    printf("GPIOA MODER (Index 0): 0x%08X\n", gpio_a_silicon[0]);
    return 0;
}