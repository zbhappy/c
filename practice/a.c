/* 加减乘除*/
#include<stdio.h>
 
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(int argc, const char *argv[])
{
    int a = 4;
    int b = 2;
    int c = 0;

    c = add(a, b);
    printf("add c = %d\n", c);

    c = sub(a, b);
    printf("sub c = %d\n", c);

    c = mul(a, b);
    printf("mul c = %d\n", c);

    c = div(a, b);
    printf("div c = %d\n", c);
    return 0;
}

int add(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int div(int a, int b)
{
    return (a / b);
}
