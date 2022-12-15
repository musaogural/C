

#include <stdio.h>

void bar(void)
{
    printf("This is the bar!");
}

void barA(int a)
{
    printf("This is the barA: %d", a);
}

int barAA(int a)
{
    printf("This is the barAA: %d", a);
    return a;
}



int main()
{
    int var = 1;

    int* ptr;

    ptr = &var;

    printf("\nDirect access, var = %d", var);
    printf("\nIndirect access, var = %d", *ptr);

    printf("\n\nThe address of var = %d", &var);
    printf("\nThe address of var = %d", ptr);
    printf("\nThe address of ptr = %d", &ptr);
    

    *ptr = 48;
    printf("\n\nIndirect access, var = %d\n\n", *ptr);

    //FUNCTION POINTER
    void (*f)(void); //f is function pointer variable to hold address of a function 
                      //that doesnt take any input argument (void), 
                      //and doesnt retrun any value void

    f = &bar;

    printf("\nThe address of f = %d", f);
    printf("\nThe address of bar = %d", &bar);
    printf("\n");

    (*f)(); //jump to the function points to f
    printf("\n");

    f();    //another usage syntx
    printf("\n");



    //FUNCTION POINTER WITH VARIABLE
    void (*ff)(int);

    ff = &barA;

    printf("\nThe address of ff = %d", ff);
    printf("\nThe address of barA = %d", &barA);
    printf("\n");

    (*ff)(3);
    printf("\n");

    ff(3);
    printf("\n");



    //FUNCTION POINTER WITH VARIABLE WITH  RETURN PARAMETER
    int (*fff)(int);

    fff = &barAA;

    printf("\nThe address of fff = %d", fff);
    printf("\nThe address of barAA = %d", &barAA);
    printf("\n");

    (*fff)(5);
    printf("\n");
    fff(5);
    printf("\n\n");

    int returnValue = (*fff)(5);
    printf("\n");
    printf("The Retrun Value: %d", returnValue);




    printf("\n\n\n");
}

