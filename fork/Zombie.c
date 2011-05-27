#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<signal.h>

int main(int argc, const char *argv[])
{
    int status;
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0)
    { 
        while(1);
  //      wait(&status);
    //    printf("the return status is %d\n", status);
    }
    /*child*/

    return 2;
}
