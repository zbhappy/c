/*约瑟夫环  数组方法*/
#include <stdio.h>

#define N   10

int main(int argc, const char *argv[])
{
    int i = 0; 
    int count = 0;   
    int num = 0;
    int a[N];
    #if 0
    printf("Input number\n");
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < N; i++)
        printf("%d\n", a[i]);
    #endif
    for(i = 0; i < N; i++)
        a[i] = i+1;

    printf("game member\n");
    for(i = 0; i < N; i++)
        printf("%d", a[i]);
        printf("\ngame:\n");
    i = 0;
    while(count < N)
    {
        
        if((num == 2)&&(a[i] != 0))
        {
            printf("%4d out\n", a[i]);
            if(count == N-1)
                printf("%4d is win\n", a[i]);
            a[i] = 0;
            num = 0;
            i++;
            count++;
        }
        else
        {
            if(a[i] != 0)
                { 
                    printf("%4d ", a[i]);
                    num++;
                    i++;
                }
            else
                i++;
        }
        if(i == N)
        {
            i = 0;
        }
    }
    return 0;
}
