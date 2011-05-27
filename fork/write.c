#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <stdio.h>
#include<stdlib.h>

#define MAX 4096
int main(int argc, const char *argv[])
{
    int fd, n;
    char buf[MAX];
    if((fd = open("./hello", O_RDWR)) < 0)
    {
        perror("open error:");
        exit(1);
    }
    
    write(fd, "hello world", 4096);

    close(fd);
    return 0;
}
