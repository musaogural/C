#include <stdio.h>
#include <stdint.h>

int main(void)
{
    for(uint8_t pinNumber; pinNumber < 16; pinNumber++)
    {
        uint8_t registerValue = (pinNumber >> 2);
        uint8_t bitNumber = ( (pinNumber & (0x03)) * 4 );

        printf("%d is pinNumber, %d is register, %d is bitValue\n", pinNumber, registerValue, bitNumber);
    }


    return 0;
}