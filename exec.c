#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    pid_t val;
    int statloc = 0;

    val = fork();

    if(val == 0)
    {
        sleep(5);
        printf("I'm in child\n");
        execl("/bin/ls", "ls", "-l", (char*) 0);
    }
    else
    {
        wait(&statloc);
        printf("I'm in parent\n");
        printf("PID: %d, PPID: %d, FORK: %d\n", getpid(), getppid(), val);
    }
    return 0;
}