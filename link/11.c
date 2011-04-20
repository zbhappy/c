
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

int sum_link(node *head);
void j_game(node *head, int n);
void print_list(void);
int get_choice(void);
node *create_link(int n);
void print_link(node *head);
node *add_link(node *head);
node *delete_link(node *head);

int main(int argc, const char *argv[])
{

    int n = 0;
    node *head = NULL;

    while(1)
    {
        print_list();
        switch(get_choice())
        {
            case 1: head = add_link(head);break;
            case 2: head = delete_link(head);break;
            case 3: print_link(head);break;
            case 4: n = sum_link(head);break;
            case 5: j_game(head, n);break;
            case 6: return 0;
            default: break;
        }
    }
    return 0;
}

void j_game(node *head, int n)
{
    int total = 0;
    int count = 0;
    node *s = NULL, *p = NULL, *q = NULL;
    p = head;

    while(total != n)
    {
        if(count == 2)
        {
            printf("%3d (Out)\n", p->number);
            q = p;
            p = p->next;
            s->next = p;
            free(q);
            count = 0;
            total++;
            

        }
        else
        {
            count++;
            printf("%3d", p->number);
            p = p->next;
            if(count == 1)
            {
                s = p;
            }
            if(p->next == NULL)
            {
                p->next  = head;
            }
        }
    }
    
}

int sum_link(node *head)
{
    node *p ;
    int n = 0;
    p = head;

    while(p != NULL)
    {
        n++;
        p = p->next;
    }
    printf("%d\n", n);
    return n;
}
int get_choice(void)
{
    char choice[20];

    scanf("%s", choice);
    return atoi(choice);
}
void print_list(void)
{
    printf("please make a choice:\n");
    printf("1. add node\n");
    printf("2. delete note\n");
    printf("3. print link\n");
    printf("4. link note total\n");
    printf("5. game\n");
    printf("6. exit\n");
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
    if(p == NULL)
    {
        printf("link empty\n");
    }
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
