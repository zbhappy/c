#include <stdio.h>
#include<string.h>

void str_test(void);

int main(int argc, const char *argv[])
{
    str_test();
    #if 0
    char *str = "welcome to china";
    char *p = str;
    char *q = str;

    while(*p != '\0')
    {
        if(*q == ' ')
        {
            if(p != q)
            {
                printf("%c", *p);
                p++;
            }
            else
            {
                p++;
                q++;
                printf("\n");
            }
        }
        else
        {
            q++;
        }
    }
    printf("\n");
    #endif
    return 0;
}
void str_test(void)
{
    char str[100] ="This is only a Game !";
    char *p = str;
    p = strtok(p ," ");
    while(p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, " ");
   // printf("%s\n", p);
    }
}
