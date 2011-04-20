#include <stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int count = 0;
    char str1[99] = "welcome tchina china" ;
    char str2[10] = "china";

    while(str1[j] != '\0'&& str2[i] != '\0')
    {
        if(str2[i] == str1[j])
        {
            i++;
            j++;
            if((str1[j] == '\0')&& (str2[i] != '\0'))
            {
                printf("nofound\n");
               
            }
            else if(str2[i] == '\0')
            {
                printf("%d\n", count);
            }
            
        }
        else
        {
            j++;
            i = 0;
            count = j;
        }
    }
//    printf("%d\n", count);
    return 0;
}
