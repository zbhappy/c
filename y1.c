/*冒泡排序*/
#include <stdio.h>
#include<stdlib.h>

#define N   10
#define M   10

int main(int argc, const char *argv[])
{
    int array[N][M];
    int i = 0;
    int j = 0;
    int *p = &array[0][0];
    int tmp = 0;

    srand(time(NULL));

    for (j = 0; j < N; j++) 
    {
        for (i = 0; i < M; i++) 
        {
            array[j][i] = rand()%(M*N);
        }
    }
    
    for(i = 0; i < (M*N - 1); i++)
    {
        for(j = i+1; j < M*N; j++)
        {
            if(p[i] > p[j])
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    for (j = 0; j < N; j++) 
    {                                               
        for (i = 0; i < M; i++) 
        {
            printf("%5d",array[j][i]); 
        }
        printf("\n");
    }
    return 0;
}
