#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0)
    {
        close(fd[0]);
     //   while(1){ 
            write(fd[1], "hello world\n", 12);
            printf("write\n");
         //   sleep(1);
       // }
        
       // printf("hell\n");
  //      n = read(fd[0], line, MAXLINE);
    //     write(STDOUT_FILENO, line, n);
      //   printf("prent\n");
        wait(NULL);
    }else{
      
        close(fd[0]);
         close(fd[1]);
      //  while(1){
       // n = read(fd[0], line, 60);
      //  write(STDOUT_FILENO, line, n);
        //sleep(1);
       // }
        
        }
    return 0;
}
