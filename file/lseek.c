#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;

    fd = open("1.txt", O_RDWR);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }
    
    lseek(fd, 10, SEEK_SET); 
    write(fd, "H", 1);

    close(fd);
    return 0;
}
