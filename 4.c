/*选择排序*/
#include<stdio.h>

int main(int argc, const char *argv[])
{
    int i, j, k;
    int a[10] = {7,6,8,1,4,9,5,3,0, 2};
    int tmp;

    for(i = 0; i < 9; i++)
    {
        k = i;
        for(j = i + 1; j < 10; j++){
            if(a[k] >a[j])
            {
                   k = j;
            }
            }
            if(k != i)
            {
                tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
    }
    for(i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    return 0;
}
