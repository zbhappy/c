#include <stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    int fd, i;
    char *p;
    fd = open("1.txt", O_RDWR);
    if(fd < 0)
    {
        perror("open file error:");
        exit(1);
    }
  //  lseek(fd, 5, SEEK_SET);//file size is 6 bytes
   // write(fd, "", 1);

    p = (char *)mmap(NULL, 10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
            perror("mmap file is error:");
            exit(1);
    }

    close(fd);

    for(i = 0; i < 10; i++)
    {
        printf(" p[%d] = %d ", i, p[i]);
    }
    printf("\n");
    munmap(p, 10);
    return 0;
}
