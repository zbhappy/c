
/* 链表练习*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int number;
    char name[20];
    struct Node *next;
}node;

node *create_link(int n);
void print_link(node *head);
node *add_link(node *head);
node *delete_link(node *head);

int main(int argc, const char *argv[])
{

    node *head = NULL;
    int n = 0;
    scanf("%d", &n);

    head = create_link(n);
   print_link(head);
   // head = add_link(head);
//    print_link(head);
    head = delete_link(head);
    print_link(head);
    return 0;
}

/*node create*/
node *create_link(int n)
{
    node *p = NULL;
    node *head = NULL;
    int i;

    p = head = malloc(sizeof(node));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    strcpy(p->name, "bao");
    p->next = NULL;

    for (i = 1; i < n; i++)
    {
        p->next = malloc(sizeof(node));
        if(p->next == NULL)
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = i+1;
        strcpy(p->next->name, "bao");
        p->next->next = NULL;
        p = p->next;
    }


    return head;
}

/*node print*/
void print_link(node *head)
{
    node *p;
    p = head;
    while(p != NULL)
    {
        printf("%d\t%s\n", p->number, p->name);
        p = p->next;
    }

}

/* node info*/
node *add_link(node *head)
{
    node *p = NULL;
    node *ptr = head;

    p= malloc(sizeof(node));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }

    printf("input number and name:\n");
    scanf("%d%s", &p->number, p->name);
    p->next = NULL;
    
    if(ptr == NULL)
    {
        return p;
    }
    
    if(p->number < ptr->number)
    {
        p->next = ptr;
        head = p;
        return head;
    }
    while((ptr->next != NULL) && (p->number > ptr->next->number))
    {
        ptr = ptr->next;
    }

    p->next = ptr->next;
    ptr->next = p;

    
    return head;
}

node *delete_link(node *head)
{
    int num ;
    node *p = NULL;
    node *q = NULL;
    p = head;

    if(head == NULL)
    {
        printf("empty link\n");
        return NULL;
    }

    printf("Please input of node to delete:\n");
    scanf("%d", &num);
    if(num == head->number)
    {
        head = head->next;
        free(p);
        return head;
    }
    while((p->next != NULL) && (p->next->number != num))
    {
        p = p->next;
    }

    if(p->next == NULL)
    {
        printf("no found\n");
    }
    else
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    return head;
}
