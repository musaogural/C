#include <stdio.h>

void func1()
{
    int x = 5;
    printf("x = %d\n", x);
    x++;
}


void func2()
{
    static int y = 5;
    printf("y = %d\n", y);
    y++;
}

int main()
{
    int k;
    printf("func1() islevi 5 kere cagiriliyor!\n");

    for(k=0; k<5; k++)
        func1();

    printf("\nfunc2() islevi 5 kere cagiriliyor!\n");

    for(k=0; k<5; k++)
        func2();

    return 0;
}
