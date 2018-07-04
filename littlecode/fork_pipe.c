#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    int fd1[2];
    int fd2[2];
    char fixed_str[] = "LEO DEBUG";
    char input_str[100];
    pid_t pid;
    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "---%s +%d---%s----LEO DEBUG-----pipe Failed---------\n", __FILE__, __LINE__, __FUNCTION__);
    }
    if (pipe(fd2)==-1)
    {
        fprintf(stderr, "---%s +%d---%s----LEO DEBUG-----pipe Failed---------\n", __FILE__, __LINE__, __FUNCTION__);
    }
    scanf("%s", input_str);
    
    /*fork another porcess*/
    pid = fork();
    if(pid<0) /*error occurred*/
    {
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if(pid==0) /*child process*/
    {
        close(fd1[1]); 
        char concat_str[100];
        // Read a string using first pipe
        read(fd1[0], concat_str, 100);
        int k = strlen(concat_str);
        int i;
        // Concatenate a fixed string with it
        for (i=0; i<strlen(fixed_str); i++)
            concat_str[k++] = fixed_str[i];
        concat_str[k] = '\0';
        // Close both reading ends
        close(fd1[0]);
        close(fd2[0]);
        // Write concatenated string and close writing end
        write(fd2[1], concat_str, strlen(concat_str)+1);
        close(fd2[1]);
        exit(0);
    }
    else /*parent process*/
    {
        char concat_str[100];
        // Write input string and close writing end of first
        // pipe.
        close(fd1[0]);
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
        // Wait for child to send a string
        wait(NULL);
        close(fd2[1]);
        read(fd2[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        close(fd2[0]);
    }
}
