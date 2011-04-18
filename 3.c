/*位运算*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    unsigned int mask = 0x0f;
    char str[20] = "0123456789abcdef";
    int d = 0;

    printf("Plesse input a number:\n");
    scanf("%d", &d);
    
    j = 28;
    for(i = 0; i < 8; i++, j -= 4)
    {
        printf("%c", str[((d>>j) & mask)]);
    }
    printf("\n");

    return 0;
}
