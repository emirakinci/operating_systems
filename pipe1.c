#include <stdio.h>
#include <unistd.h>

int main(void){
    int fd[2];
    int id;
    if(pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe error!!");
    }

    id = fork();

    if(id == -1)
    {
        fprintf(stderr, "Fork error!!");
    }

    if(id == 0) // I'm in child process
    {
        close(fd[0]);
        char my_Str[11+1];
        printf("type your str:\n");
        scanf("%s", my_Str);

        if(write(fd[1], my_Str, sizeof(my_Str)) == -1)
        {
            fprintf(stderr, "File write error!");
        }
        close(fd[1]);
    }
    else // I'm in parent process
    {
        close(fd[1]);
        char str[11+1];

        if(read(fd[0], str, sizeof(str)) == -1) 
        {
            fprintf(stderr, "File read error!");
        }
        close(fd[0]);

        printf("the string comming from child process is: %s\n", str);
    }
    return 0;
}