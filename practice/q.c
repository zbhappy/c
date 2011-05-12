#include <stdio.h>

struct A
    {
      short i;
      short j;
      char* ptr;
      long array[100];
      char b[4];
      char * c;
    };

#define PRINT_ME    (char *)&(((struct A *)0)->c)
int main(int argc, const char *argv[])
{
    #if 0
    char a[10] = {0,1,2,3,4,5};
    short *p = (short *)(a+2);
    short i = *p;
    printf("%x\n", i);
    #endif
    #if 0
    int a = 1, b;

    for (b = 1; b <= 10; b++) 
    {
        if(a >= 8)
            break;
        if(a%2 == 1) 
        {
            a+=5;
            continue;
        }
     a-=3;
    }
    printf("%d\n", b);
    #endif

    #if 0
    int a;
    int *p;
    p = &a;
    *p = 0x500;
    a = (int)(*(&p));
    if(a == (int)p)
        printf("equal!\n");
    else
        printf("not equal!\n");

    a = (int)(&(*p));
    if(a == (int)p)
        printf("equal!\n");
    else
        printf("not equal!\n");
    #endif                            

    #if 0
    struct st_t
    {
        int status;
        short* pdada;
        char errstr[32];
    };
    struct st_t st[16];
    char*p = (char*)(st[2].errstr +32);
    printf("%d", (p - (char*)(st)));
    #endif

    #if 0
    const char* p = "12345";
    const char **q = &p;
    *q = "abcde";
   // printf("%s\n", p);
    const char *s = ++p;
    p = "XYZWVU";
    printf("%c\n", *++s);
    #endif

    #if 1
    printf("%d\n", PRINT_ME);
    printf("%d\n", sizeof(long));
    #endif
    return 0;
}
