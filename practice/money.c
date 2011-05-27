#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    int i = 0, j = 0;
    FILE *fp;
    int m = 0, count = 0;
    int n = 0, tmp = 0;
    int T[100];
    int C[100];

    fp = fopen("input.txt", "r+");
    if(fp == NULL)
    {
        printf("open error");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    for(i = 0; i < n; i++){
        fscanf(fp, "%d%d", &T[i], &C[i]);
    }
    fscanf(fp,"%d", &m);
    

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(T[i] < T[j])
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;

                tmp = C[i];
                C[i] = C[j];
                C[j] = tmp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        while(C[i] != 0)
        {
            if((m - T[i]) >= 0){
                m = m - T[i];
                C[i] = C[i] - 1;
                count++;
            }
            else
                break;
        }
    }
    printf("%d\n", count);
    fclose(fp);
    return 0;
}
