#include <stdio.h>
#include <stdint.h>

#define DISABLE     (0x0)
#define ENABLE      (!DISABLE)

#define GPIO_Pin_0      (0x0001)
#define GPIO_Pin_1      (0x0002)
#define GPIO_Pin_2      (0x0004)
#define GPIO_Pin_3      (0x0008)



void GPIO_WritePin(uint32_t *registerValue, uint8_t pinNumber, uint8_t pinState)
{
    if(pinState == ENABLE)
    {
        *registerValue = pinNumber;
    }
    else
    {
        *registerValue |= (pinNumber + 16U);
    }

}


int main(void)
{
    uint32_t GPIO_BSRR_Register = 0x0;
    
    //GPIO_BSRR_Register |= (0x1 << 7);

    GPIO_WritePin(&GPIO_BSRR_Register, GPIO_Pin_1 | GPIO_Pin_2, ENABLE);

    printf("%d = %#X\n", GPIO_BSRR_Register, GPIO_BSRR_Register);

    GPIO_WritePin(&GPIO_BSRR_Register, GPIO_Pin_1 | GPIO_Pin_2, DISABLE);

    printf("%d = %#X\n", GPIO_BSRR_Register, GPIO_BSRR_Register);


    return 0;
}