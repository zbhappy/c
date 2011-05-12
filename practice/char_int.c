#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char *int_char(char str[], int num)
{
    int i = 0;
    int num1;
    if(num >= 0 && num < 10)
    {
        num1 = 1;
    }
    if(num >= 10 && num < 100)
    {
                num1 = 10;
    }
    if(num >= 100 && num < 1000)
    {
        num1 = 100;
    }

    if(num >= 1000 && num < 10000)
    {
        num1 = 1000;
    }


    while(num1 > 0)
    {
      str[i]  = (num/num1 + '0');
      num = num - num1*(str[i] - '0');
      num1 = num1/10;
      i++;
    }
    str[i] = '\0';

    return str;
}
#if 0
int char_int(char *str)
{
    int i = 0;
    int num = 0;

    for(i = 0; i < strlen(str); i++)
    {
        num = num*10 + (str[i] - '0');
    }
    return num;
}
#endif
int main(int argc, const char *argv[])
{
   char str[100];
   // int i = 0;
    int number = 0;
    char *p;

   // printf("please input the digit_character:");
   // scanf("%s", str);
    printf("please input the number:");
    scanf("%d", &number);
    #if 0
    for(i = 0; i < strlen(str); i++)
    {
       if(!isdigit(str[i]))
       {
          printf("input error\n");
          exit(1);
       }
    }

    number = char_int(str);

    printf("the number is %d\n", number);
    #endif
    
    p = int_char(str, number);
    printf("%s\n", p);
    return 0;
}

