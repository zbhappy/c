#include <stdio.h>
#include<string.h>

char * arry_change(char *str)
{
    int i = 0, j = 0;
    int tmp = 0;
    int n1 = strlen(str)/2;
    int n2 = strlen(str);
    
    if((n2%2) == 0)
    {
        j = n1;
    }
    else
    {
        j = n1 +1;
    }
    for(i = 0, j; i < n1, j < n2; i++, j++)
    {
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;

    }
    return str;
}
int main(int argc, const char *argv[])
{
    char str[100] = "abchdef";
    char *p;
    p = arry_change(str);

    printf("%s", p);
    printf("\n");

    return 0;
}
