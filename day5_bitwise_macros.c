#include <stdio.h>
#include <stdint.h>

// Industry-standard bitwise macros
#define SET_BIT(REG, BIT)     ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))
#define TOGGLE_BIT(REG, BIT)  ((REG) ^= (1 << (BIT)))
#define READ_BIT(REG, BIT)    ((REG) & (1 << (BIT)))
int main() {
    uint8_t control_reg = 0x00; 
    printf("Initial: 0x%02X\n", control_reg);

    // 1. Set bits 2 and 5
    SET_BIT(control_reg, 2);
    SET_BIT(control_reg, 5);
    printf("After Setting bits 2 and 5: 0x%02X\n", control_reg);

    // 2. Clear bit 2
    CLEAR_BIT(control_reg, 2);
    printf("After Clearing bit 2: 0x%02X\n", control_reg);

    // 3. Toggle bit 7
    TOGGLE_BIT(control_reg, 7);
    printf("After Toggling bit 7: 0x%02X\n", control_reg);

    // 4. Read bit 7 and bit 2
    if (READ_BIT(control_reg, 7)) {
        printf("Bit 7 is HIGH\n");
    }
    
    if (!READ_BIT(control_reg, 2)) {
        printf("Bit 2 is LOW\n");
    }

    return 0;
}