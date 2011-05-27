#include <stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

#define N   24
int main(int argc, const char *argv[])
{
    int fd1, fd2;
    char buf[N];
    int n = 0;
    
    if(argc != 3)
    {
        printf("please input(./mycp 1.txt 2.txt)\n");
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1)
    {
        perror("open");
        exit(0);
    }

    fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(fd2 == -1)
    {
        perror("open");
        exit(0);
    }

    while((n = read(fd1, buf, N)))
    {
        write(fd2, buf, n);
    }

    close(fd2);
    close(fd1);
    return 0;
}
