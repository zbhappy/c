
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

#define MSG_TRY "try again\n"

int main(int argc, const char *argv[])
{
    int fd;
    char buf[10];
    int n;
    int flags;
    fd = open("/dev/tty", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }
    flags = fcntl(fd, F_GETFL);
    flags |= O_NONBLOCK;
    if(fcntl(fd, F_SETFL, flags) == -1)
    {
        perror("fcntl");
        exit(1);
    }
    tryagain:
    n = read(fd, buf, 10);
    if(n < 0)
    {
        if(errno == EAGAIN)
        {
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            goto tryagain;
        }
        perror("read stdin");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    
    close(fd);
    return 0;
}
