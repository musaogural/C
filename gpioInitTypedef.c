#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define __IO    volatile

typedef struct
{
	__IO uint32_t MODER;			/*!< GPIO port mode register 				Address offset: 0x00 */
	__IO uint32_t OTYPER;			/*!< GPIO port output type register 		Address offset: 0x04 */
	__IO uint32_t OSPEEDR;			/*!< GPIO port output speed register 		Address offset: 0x08 */
	__IO uint32_t PUPDR;			/*!< GPIO port pull-up/pull-down register 	Address offset: 0x0C */
	__IO uint32_t IDR;				/*!< GPIO port input data register 		 	Address offset: 0x10 */
	__IO uint32_t ODR;				/*!< GPIO port output data register 		Address offset: 0x14 */
	__IO uint32_t BSRR;				/*!< GPIO port bit set/reset register		Address offset: 0x18 */
	__IO uint32_t LCKR;				/*!< GPIO port configuration lock register 	Address offset: 0x1C */
	__IO uint32_t AFR[2];			/*!< GPIO alternate function 				Address offset: 0x20 */

}GPIO_TypeDef_t;


typedef struct 
{
    uint32_t pinNumber;
    uint32_t Mode;
    uint32_t OTYPE;
    uint32_t PuPd;
    uint32_t speed;

}GPIO_InitTypedef_t;

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypedef_t *GPIO_Config)
{
    GPIOx->MODER = GPIO_Config->Mode;
    GPIOx->OTYPER = GPIO_Config->OTYPE;

}


int main(void)
{

GPIO_TypeDef_t *GPIOA = (GPIO_TypeDef_t*) malloc(sizeof(GPIO_TypeDef_t));
GPIO_TypeDef_t *GPIOB = (GPIO_TypeDef_t*) malloc(sizeof(GPIO_TypeDef_t));

GPIO_InitTypedef_t GPIO_InitStructure = { 0 };
GPIO_InitStructure.pinNumber = 0xB;
GPIO_InitStructure.Mode = 0x3;
GPIO_InitStructure.OTYPE = 0x1;
GPIO_InitStructure.PuPd = 0x2;
GPIO_InitStructure.speed = 0x3;

GPIO_Init(GPIOA, &GPIO_InitStructure);

printf("Mode = %#X = %d, OTYPE = %#X = %d", GPIOA->MODER, GPIOA->MODER, GPIOA->OTYPER, GPIOA->OTYPER);




free(GPIOA);
    return 0;
}