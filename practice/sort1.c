#include <stdio.h>

typedef struct
{
    int a;
    int num;
}arry;

arry *sort(arry b[])
{
    int count = 0;
    int tmp = 0;
    int tmp1 = 0;
    int i = 0, j = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if((b[i].a>>j) & 0x01)
            {
                count++;
            }
        }
        b[i].num = count;
        count = 0;
    }

    for(i = 0; i < 4; i++)
    {
        for(j = i+1; j < 5; j++)
        {
            if(b[i].num > b[j].num)
            {
                tmp = b[i].a;
                tmp1 = b[i].num;
                b[i].a = b[j].a;
                b[i].num = b[j].num;
                b[j].a = tmp;
                b[j].num = tmp1;
            }
        }
    }
    return b;
}
int main(int argc, const char *argv[])
{
    int b[5] = {5,4,3,2,1};
    int i = 0;
    arry a[5];
    arry *p;

    for(i = 0; i < 5; i++)
    {
        a[i].a = b[i];
    }

    p = sort(a);
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", p[i].a);
    }
    return 0;
}
