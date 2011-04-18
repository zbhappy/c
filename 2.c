/*位运算*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int d = 0, i = 0, j = 31;
    unsigned int mask = (0x01 << (sizeof(int)*8 - 1));

    puts("Please input a number:");
    scanf("%d", &d);

    puts("result:");
    #if 0 
    for(i = 0; i < sizeof(int)*8; i++, j--)
    {
        printf("%d",((d>>j)& 0x01));
        
      //  printf("%d",(d & 0x01));
      //  d >>= 1;
       
    }
    #endif
    for(i = 0; i < sizeof(int)*8; i++)
    {
        
       // printf("%d",(((d << i) & 0x80000000) != 0 ? 1: 0));
        printf("%d",((d & mask) != 0 ? 1: 0));
        mask >>= 1;
    }
       
    printf("\n");
    return 0;
}
