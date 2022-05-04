#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t myArr[] = { 1, 3, 5, 12, 6, 58, 12 };
    uint32_t *pmyArr = myArr;

    printf("Before Operation Adress: %p \n", pmyArr);

    //pmyArr = pmyArr + 1;

    printf("After Operation Adress: %p \n", pmyArr);

    *(pmyArr + 3) = 99;

    printf("After Operation myArr[3]= %d \n", myArr[3]);

    for(int i = 0; i < 7; i++)
    {
        printf("%p\n",  (pmyArr + i));
    }

        for(int i = 0; i < 7; i++)
    {
        printf("%d\n", *(pmyArr + i));
    }




    return 0;
}