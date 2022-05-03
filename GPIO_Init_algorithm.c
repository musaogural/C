#include <stdio.h>
#include <stdint.h>


#define GPIO_PIN_0		(uint16_t)(0x0001) /*!< GPIO Pin 0 Selected */
#define GPIO_PIN_1		(uint16_t)(0x0002) /*!< GPIO Pin 1 Selected */
#define GPIO_PIN_2		(uint16_t)(0x0004) /*!< GPIO Pin 2 Selected */
#define GPIO_PIN_3		(uint16_t)(0x0008) /*!< GPIO Pin 3 Selected */
#define GPIO_PIN_4		(uint16_t)(0x0010) /*!< GPIO Pin 4 Selected */
#define GPIO_PIN_5		(uint16_t)(0x0020) /*!< GPIO Pin 5 Selected */
#define GPIO_PIN_6		(uint16_t)(0x0040) /*!< GPIO Pin 6 Selected */
#define GPIO_PIN_7		(uint16_t)(0x0080) /*!< GPIO Pin 7 Selected */
#define GPIO_PIN_8		(uint16_t)(0x0100) /*!< GPIO Pin 8 Selected */
#define GPIO_PIN_9		(uint16_t)(0x0200) /*!< GPIO Pin 9 Selected */
#define GPIO_PIN_10		(uint16_t)(0x0400) /*!< GPIO Pin 10 Selected */
#define GPIO_PIN_11		(uint16_t)(0x0800) /*!< GPIO Pin 11 Selected */
#define GPIO_PIN_12		(uint16_t)(0x1000) /*!< GPIO Pin 12 Selected */
#define GPIO_PIN_13		(uint16_t)(0x2000) /*!< GPIO Pin 13 Selected */
#define GPIO_PIN_14		(uint16_t)(0x4000) /*!< GPIO Pin 14 Selected */
#define GPIO_PIN_15		(uint16_t)(0x8000) /*!< GPIO Pin 15 Selected */
#define GPIO_PIN_ALL	(uint16_t)(0xFFFF) /*!< GPIO Pin All Selected */

#define GPIO_MAX_PIN_NUMBER     (16U)


int main(void)
{
    uint16_t GPIO_Pin_Config = GPIO_PIN_3 | GPIO_PIN_12 | GPIO_PIN_15;



    for(uint16_t position = 0; position < GPIO_MAX_PIN_NUMBER; position++)
    {
        uint16_t fakeValue = (0x1U << position);
        uint16_t isThere = GPIO_Pin_Config & fakeValue;


        if(isThere == fakeValue)
        {
            printf("%d is your position = pin Value\n",position);
            printf("%#X is your fakeValue\n", fakeValue);
            printf("%#X is your isThere value\n", isThere);
            printf("\n\n\n");
        }


    }




    return 0;
}