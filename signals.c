#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int num)
{
    printf("\nI wont die XD %d\n", num);
    return ;
}

int main(void){
    int pid;
    signal(SIGTSTP, handler);
    while(1)
    {
        pid = getpid();
        printf("Wasting your cycles: %d\n", pid);
        sleep(5);
        //raise(SIGTSTP);
    }
    return 0;
}