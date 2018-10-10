// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// int main(void)
// {
//     // Your code here
//     FILE *file;
//     // The C library function FILE *fopen(const char *filename, const char *mode) opens the filename pointed to, by filename using the given mode.
//     file = fopen("text.txt", "r+"); //"r+" Opens a file to update both reading and writing. The file must exist

//     printf("Parent process, pid is %d\n", getpid());
//     int pid = fork();

//     if (pid < 0)
//     {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     }
//     else if (pid == 0)
//     {
//         printf(file, "%s: %d\n", "Child process", getpid());
//     }
//     else
//     {
//         printf(file, "%s\n", "Parent process again");
//     }
//     fclose(file);

//     return 0;
// }

// solution
int main(void)
{
    // Your code here
    FILE *fp;

    fp = fopen("text.txt", "r+");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork Failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("child here\n");
        char *child_str = "This is child string. \n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    }
    else
    {
        printf("parent here\n");
        char *parent_str = "This is parent string. \n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    }

    fclose(fp);

    return (0);
}