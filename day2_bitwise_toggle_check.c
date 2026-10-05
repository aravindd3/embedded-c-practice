#include <stdio.h>
#include <stdint.h>
int main() {
    uint8_t status_reg = 0b10000000; 
    printf("Initial register: 0x%02X\n", status_reg);
    
    // 1. Toggle the 4th bit
    status_reg ^= (1 << 4);

    // 2. Check if the 7th bit is high
    // TODO: Write an if-statement using & and << to isolate the 7th bit
    if (status_reg & (1<<7)) {
        printf("The 7th bit is HIGH.\n");
    } else {
        printf("The 7th bit is LOW.\n");
    }
    printf("Final register after toggle: 0x%02X\n", status_reg);
    return 0;
}