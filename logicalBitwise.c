#include <stdio.h>
#include <stdint.h>

int main(void)
{
    
    /* Logical Bitwise Operators */ 
    uint8_t numberOne = 0x4; //0000 0100
    uint8_t numberTwo = 0x2; //0000 0010
    uint8_t result = 0;
   
    result = numberOne & numberTwo; //0000 0000
    printf("AND: %#X = %d\n", result, result);

    result = numberOne | numberTwo; //0000 0110
    printf("OR: %#X = %d\n", result, result);

    result = numberOne ^ numberTwo; //0000 0110
    printf("AND: %#X = %d\n", result, result);

    result = ~numberOne;            //1111 1011
    printf("AND: %#X = %d\n", result, result);

    printf("\n\n\n");

    /* Shift Operators */

    uint32_t AHB1ENR = (0x1 << 5); //00010 0000
    printf("AHB1ENR: %#X = %d\n", AHB1ENR, AHB1ENR);

    AHB1ENR |= (0x1 << 4);         //0001 0000 -> 0011 0000
    printf("AHB1ENR: %#X = %d\n", AHB1ENR, AHB1ENR);

    AHB1ENR |= (0x1 << 0);         //0011 0000 -> 0011 0001
    printf("AHB1ENR: %#X = %d\n", AHB1ENR, AHB1ENR);

    printf("\n\n\n");

    uint32_t readAHB1ENR;
    readAHB1ENR = ((AHB1ENR >> 4) & 0x1);
    printf("4th Value: %#X = %d\n", readAHB1ENR, readAHB1ENR);

    readAHB1ENR = ((AHB1ENR >> 0) & 0x1);
    printf("0th Value: %#X = %d\n", readAHB1ENR, readAHB1ENR);

    readAHB1ENR = ((AHB1ENR >> 2) & 0x1);
    printf("2th Value: %#X = %d\n", readAHB1ENR, readAHB1ENR);

    printf("\n\n\n");

    uint8_t newValue = 0; //0000 0000

    newValue |= (0xF << 0); //0000 1111
    printf("New Value: %#X = %d\n", newValue, newValue);

    newValue |= (0xF << 2); //0011 1100
    printf("New Value: %#X = %d\n", newValue, newValue);

    newValue |= (0x7 << 2); //0011 1111
    printf("New Value: %#X = %d\n", newValue, newValue);

    newValue ^= (0x1 << 2); //0000 0100 -> 0011 1011
    printf("New Value: %#X = %d\n", newValue, newValue);

    newValue &= ~(0x1 << 1); //0011 1001
    printf("New Value: %#X = %d\n", newValue, newValue);

    newValue &= ~(0x1 << 3); //0011 0001
    printf("New Value: %#X = %d\n", newValue, newValue);


    return 0;
}