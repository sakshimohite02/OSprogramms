#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(5);  // Sleep to ensure the parent process terminates first
        printf("Child process with PID %d, Parent PID after becoming orphan: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process with PID %d is terminating.\n", getpid());
        exit(0);  // Parent process terminates immediately
    }

    return 0;
}
