#include <stdio.h>
#include <stdint.h>
int main() {
    // Binary: 0b1101 1010 0111 0011 (0xDA73)
    // Bits 2-5 currently hold the value 12 (1100)
    uint16_t radio_config_reg = 0xDA73; 
    
    // The new transmission power level we want to insert
    uint8_t new_tx_power = 5; // Binary: 0101

    // TODO: Perform the Read-Modify-Write sequence
    // Step 1: Clear bits 2 through 5 in the register using & and an inverted mask (~)
    // Step 2: Shift 'new_tx_power' into the correct position
    // Step 3: Insert the shifted value into the register using |
    radio_config_reg &= ~(0b000000000111100);
    new_tx_power <<= 2;
    radio_config_reg |=new_tx_power;
    
    printf("Original Register: 0xDA73\n");
    printf("Updated Register : 0x%04X\n", radio_config_reg);
    
    return 0;
}