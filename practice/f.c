#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   100
void print_array(int *p)
{
    int i = 0;
    int j = 0;

    for(i = 0; i < N; i++)
    {
        if(p[i] > 0)
        {
            
            if((j%7) == 0)
                printf("\n");
                j++;
            printf("%5d", p[i]);
        }
    }
    printf("\n");
   
}

void init_array(int *p)
{
    int i = 0;
    srand(time(NULL));
    for (i = 0; i < N; i++) 
    {
        p[i] = (rand()%20);
    }
}

void sort_array(int *p)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < N-1; i++) 
    {
        if(p[i] > 0)
        {
            for(j = i +1; j < N; j++)
            {
                if(p[j] == p[i])
                {
                    p[j] = -1;
                }
            }
        }
    }
}
int main(int argc, const char *argv[])
{
    int array[N]; 
    init_array(array);
    print_array(array);
    sort_array(array);
    printf("\n\n\n");
    print_array(array);


    return 0;
}
