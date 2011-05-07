#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define N   100

void find_t(char *s, int n);
void bit_t();
#if 0
void print(int a[100], int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < N; i++) 
    {
        if((i % 10) == 0)
        {
            printf("\n");
        }
        else
        {
            printf("%3d", a[i]);
        }    
    }
    printf("\n");
}
#endif
#if 0
void sort_t(int a[100], int n)
{
    int i = 0;
    int j = 0;
   // int k = 0;
    int temp = 0;

    for (i = 0; i < N - 2; i++) 
    {
     //   k = a[i];
        for (j = i + 1; j < N; j++) 
        {
            if(a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

}
#endif

int main(int argc, const char *argv[])
{
  //  int a[N] = {0};
    //int i = 0;
    //int j = 0;
    //int n = 0;
    char str[N] = "hello world hehe world!";
/*
    srand(time(NULL));
    for(i = 0; i < N; i++)
    {
        
        n = rand()%100;
        for(j = 0; j < i; j++)
        {
            if(a[j] == n)
            {
                i--;
                break;
            }
            else
            {
                a[i] = n;
            }
        }
    }

    print(a, N);
    sort_t(a, N);
    printf("sort:\n");
    print(a, N);
    */
    find_t(str, strlen(str));
    return 0;
}
void find_t(char *s, int n)
{
    /*
    char c;
    int i = 0;
    int j = 0;
    //char str1[20] = "world";

//    printf("input the character:");
 //   scanf("%c", &c);
 //   printf("input the world 0~19:\n");
   // scanf("%s", str1);

    for (i = 0; i < n; i++) 
    {
        
       // if(s[i] == c)
       // {
         //   printf("the %d \n", i);
       // }
        if(strncmp(s++, str1, strlen(str1)) == 0)
        {
            printf("the world %d \n", i);
            
        }
        
    }
    */
    bit_t();
}

void bit_t()
{
    int num = 0;
    int i = 0;
    int j = 0;
    unsigned int max = ((0x01)<<(sizeof(int)*8 - 1)); 

    printf("Input the num:");
    scanf("%d", &num);

    for (i = 0; i < sizeof(int)*8; i++) 
    {
        printf("%d", ((num&max) > 0)?1:0);
    //      printf("%d", (num&max));
        if((num&max) >0)
        {
            j++;
        }
        max >>= 1;
    }
    printf("\n");
    printf("%d", j);
    printf("\n");
}
