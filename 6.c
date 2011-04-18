/*字符串*/
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[20] = "This is a C world!";
  //  char c_str[20];
    char *p = str;
    char *s = str, *tmp;

    while(*s != '\0')
    {
        while(*s == ' ') s++;
        if(p != s)
        {
            *p = *s;
        }
        p++;
        s++;
    }
    *p = '\0';
    printf("len = %d\t%s\n", strlen(str), str);
    puts(str);
   // char *p_c = c_str;
/*
    while(*p != '\0')
    {
        if(*p != ' ')
            p++;
        else
        {
        q = p;
        tmp = q;
        tmp++;
        while(*tmp != '\0'){
            *q = *tmp;
            q++;
            tmp++;}
            *q = '\0';
        }
     }
     *p = '\0';
     puts(str);
  */  
   /* while(*p != '\0')
    {
        if(*p == ' ')
            p++;
        else
        {
            *p_c = *p;
            p++;
            p_c++;
        }
    }
    *p_c = '\0';
    p_c = c_str;
    printf("%s\n", c_str);
    while(*p_c != '\0')
    {
        putchar(*p_c);
        p_c++;
    }
    printf("\n");
    */
/*
    while(*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
    while(p >= str)
    {
        printf("%c", *p);
        p--;
    }
    printf("\n");
    */
    return 0;
}
