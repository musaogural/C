#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t variable[2] = { 1, 14 };
    uint32_t *pVariable = &variable;

    uint32_t temp = (uint32_t) pVariable;

    printf("\n%p is your pointer, %X is your temp value", pVariable, temp);

    temp += 0x4;

    *((uint32_t*)temp) = 22;

    printf("\n%p is your pointer, %X is your temp value", pVariable, temp);
    printf("\nVariable[1] = %d",variable[1]);


    return 0;
}