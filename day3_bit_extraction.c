#include <stdio.h>
#include <stdint.h>
int main() {
    // Binary: 0b1101 1010 0111 0011 (0xDA73)
    uint16_t radio_config_reg = 0xDA73; 

    // TODO: Extract the 4-bit transmission power level located at bits 2 through 5.
    // Step 1: AND the register with a binary mask to isolate the bits.
    // Step 2: Right-shift (>>) the result by 2 positions to bring it down to the LSB.
    
    uint8_t tx_power =(radio_config_reg & 0b00000000111100)>>2;
    
    printf("Raw Configuration Register: 0x%04X\n", radio_config_reg);
    printf("Extracted TX Power Level: %u\n", tx_power);
    return 0;
}