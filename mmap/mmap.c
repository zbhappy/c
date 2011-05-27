#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/mman.h>

int main(int argc, const char *argv[])
{
    int fd1, fd2, stat;
    struct stat buf;
    int *p1, *p2;

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0)
    {
        perror("open");
        exit(1);
    }


    fd2 = open(argv[2], O_RDWR|O_CREAT, 0644);
    if(fd2 < 0)
    {
        perror("open");
        exit(1);
    }

    stat = fstat(fd1, &buf);
    if(stat < 0)
    {
        perror("fstat");
        exit(1);
    }
    lseek(fd2, buf.st_size -1, SEEK_SET);
    write(fd2, "1", 1);

    p1 = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
    if(p1 == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd1);

    p2 = mmap(NULL, buf.st_size, PROT_WRITE|PROT_READ, MAP_SHARED, fd2, 0);

    if(p2 == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd2);

    memcpy(p2, p1, buf.st_size);

    munmap(p1, buf.st_size);
    munmap(p2, buf.st_size);

    //printf("%d\n", buf.st_size);
    return 0;
}
