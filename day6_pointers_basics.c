#include <stdio.h>
#include <stdint.h>
int main() {
    // 1. A standard variable stored somewhere in RAM
    uint32_t sensor_data = 1024;
    
    // 2. A pointer holding the exact memory address of 'sensor_data'
    // The '&' operator extracts the memory address of a variable
    uint32_t *pData = &sensor_data;
    printf("Value of sensor_data: %u\n", sensor_data);
    printf("Memory address of sensor_data: %p\n",*pData);

    // 3. Dereferencing the pointer to modify the original variable
    // The '*' operator allows us to reach into that memory address and change the data
    *pData = 4096;
    printf("\nAfter modifying via pointer:\n");
    printf("New value of sensor_data: %u\n", sensor_data);
    return 0;
}