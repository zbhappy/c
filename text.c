
/*结构体练习*/

#include<stdio.h>
#include<string.h>

typedef struct Node
{
    int number;
    char name[20];
    int score;
    struct node *next;
}node;

int main(int argc, const char *argv[])
{
     node stu;
     node *ptr = NULL;
     ptr = &stu;

     printf("Please input the student information eg(number, name, score):\n");
     scanf("%d", &ptr->number);
     scanf("%s", ptr->name);
     getchar();
     scanf("%d", &ptr->score);
     printf("number: %d\tname: %s\t score: %d\n", ptr->number, ptr->name, ptr->score);
    
     return 0;
}
