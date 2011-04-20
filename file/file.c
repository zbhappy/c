#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    int i;
    char ch;
    char s[100];
    char str[100] = "hello world!\nthis is C world\n";
    char str1[100] = {0};
    int num = 1;
    int num1 = 2;
  
    fp = fopen("text", "r+");
    if(fp == NULL)
    {
        perror("Open");
        exit(0);
    }
/* fgetc and fputc  fgetc = putc  fgetc = getc*/
    #if 1
    for(i = 0; str[i] != '\0'; i++)
        fputc(str[i], fp);
    rewind(fp);
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    #endif
/* gets and puts    dangerous */

/* fgets and fputs */
    #if 0
     fputs(str, fp);
     rewind(fp);
     fgets(s, 99, fp);
     if(s == NULL)
     {
        perror("fgets");
        exit(0);
     }
     printf("%s\n", s);

     i = ftell(fp);

     printf("%d", i);
     fgets(s, 99,fp);
     printf("%s\n", s);
    #endif

/* fprintf and fscanf */
    #if 0
  //  fprintf(fp, "%s,%d,%d", str, num,num1);

    fscanf(fp, "%s,%d,%d", str1, &num, &num1);
    printf("str = %s, num = %d, num1 = %d\n", str1, num, num1);
    #endif
    fclose(fp);
    return 0;
}
