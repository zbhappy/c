/*进制转换*/
#include<stdio.h>

int main(void)
{
        int c = -127;
        int tmp[8] = {0} , i = 0;
        while(c != 1){
            tmp[i] = c % 2;
            c = c/2;
            i++;}
        tmp[i] = 1;
        for(i = 7; i >= 0; i--)
        printf("%d", tmp[i]);
        printf("\n");
}

