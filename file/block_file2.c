#include <stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MSG_TRY "try again\n"
#define MSG_TIMEOUT  "timeout\n"

int main(int argc, const char *argv[])
{
    char buf[10];
    int fd, n, i;
    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
    if(fd < 0)
    {
        perror("open /dev.tty");
        exit(1);
    }
    for (i = 0; i < 5; i++) 
    {
        n = read(fd, buf, 10);
        if(n >= 0)
        {
            break;
        }
        if(errno != EAGAIN)
        {
            perror("read/dev/tty");
            exit(1);
        }
        sleep(1);
        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
    }
    if(5 == i)
        write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
    else 
        write(STDOUT_FILENO, buf, n); 
    close(fd);
    return 0;
}
