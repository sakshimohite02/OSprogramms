#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // Error in fork
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) will now run 'ls' command\n", getpid());

        // Replace child process image with the "ls" command
        execl("/bin/ls", "ls", NULL);

        // If exec() fails, the following code will execute
        perror("exec failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process (PID: %d) waiting for child to complete...\n", getpid());

        // Wait for the child process to terminate
        wait(NULL);

        printf("Child process has terminated, control returned to parent process\n");
    }

    return 0;
}
