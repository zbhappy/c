#include <stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
    char str[100] = "welcom to changchun";
    int i = 0;

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] != ' ')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("%s\n", str);
    return 0;
}
