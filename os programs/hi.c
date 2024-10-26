#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Create a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: Hello World\n");
        printf("Child Process ID: %d\n", getpid());
    } else {
        // Parent process
        printf("Parent Process: Hi\n");
        printf("Parent Process ID: %d\n", getpid());
    }

    return 0;
}
