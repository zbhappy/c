#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a, ch;
    printf("input some chars:\n");
    scanf("%c", &a);
    printf("a = %c\n", a);

    while((ch = getchar()) != '\n');

    printf("input again chars:\n");
    scanf("%c", &a);
    printf("a = %c\n", a);
    return 0;
}
