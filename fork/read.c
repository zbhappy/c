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
    
    n = read(fd, buf, 4096);
    if(n < 0)
    {
        perror("read error:");
        exit(1);
    }
    printf("read data is: %s\n", buf);

    close(fd);
    return 0;
}
