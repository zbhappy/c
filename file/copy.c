#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp, *fq;
    int n = 0;
    char buf[100] = "heheheheheheheheh";
    char buf1[100];

    if(argc != 3)
    {
        printf("please input:./* 1.txt, *.txt");
    }
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror("open");
        return -1;
    }
   
    n = fread(buf1, 1, strlen(buf), fp);
    printf(" n = %d\n", n);

    fq = fopen(argv[2], "wb");
    if(fp == NULL)
    {
       perror("open");
       return -1;
    }

    fwrite(buf1, 1, n, fq);

    fclose(fq);
    fclose(fp);

    return 0;
}
