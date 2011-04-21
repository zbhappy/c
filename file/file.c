#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, const char *argv[])
{
    FILE *fp, *fq;
    int i = 0, n = 0;
    char ch;
    char s[100];
    char str[100] = "hello world!\nthis is C world";
    char str1[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int num = 1;
    int num1 = 2;
    //  str[6] = 0;  
    fp = fopen("text", "r+");
    if(fp == NULL)
    {
        perror("Open");
        exit(0);
    }

    fq = fopen("tex", "r+");
    if(fq == NULL)
    {
        perror("Open");
        exit(0);
    }


/* fwrite and fread */
#if 1
    //    fwrite(str, 1, 100, fp);
        while(feof(fp) == 0)
        {
            i += fread(&str1[n], 1, 4, fp);
            n += 4;
        }
        printf("%d, %d\n", i, n);
        if(i != 0){

            str1[i] = '\0';
            fwrite(str1, 1, i, fq);
            printf("%s", str1);
            
            }
#endif
    fclose(fq);
    /* fgetc and fputc  fgetc = putc  fgetc = getc*/
#if 0
    for(i = 0; str[i] != '\0'; i++)
        fputc(str[i], fp);
    rewind(fp);
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    printf("%d\n", str[6]);
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
