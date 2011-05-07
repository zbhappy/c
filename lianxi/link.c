#include <stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int number;
    char sex;
    struct NODE *next;

}node;

node *init_link(int n)
{
    node *head = NULL;
    node *p = NULL;
    int i = 0;
    FILE *fp;

    p = head = malloc(sizeof(node));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }
    printf("please input the num and sex");
    scanf("%d%c",&p->number, &p->sex );
    p->next = NULL;
    n--;

    for(i = 0; i < n; i++)
    {
        p->next = malloc(sizeof(node));
        if(p->next == NULL)
        {
            printf("malloc");
            exit(0);
        }
        printf("please input the num and sex");
        scanf("%d%c",&p->next->number, &p->next->sex );
        p->next->next = NULL;
        p = p->next;
    }
    p = head;
    fp = fopen("txt", "w+");
    if(fp == NULL)
    {
        perror("open");
        exit(0);
    }
    while(p != NULL)
    {
        fprintf(fp, "%d\t%c\n", p->number, p->sex);
        p = p->next;
    }
    fclose(fp);
    return head;
}
int main(int argc, const char *argv[])
{
    node *head = NULL;
    int n;
    printf("please input the link num:");
    scanf("%d", &n);
    printf("\n");
    head = init_link(n);
    return 0;
}
