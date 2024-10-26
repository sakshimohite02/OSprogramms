#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Error handling if fork() fails
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process with PID %d\n", getpid());
        
        // Get and print the initial priority of the child process
        int initial_nice = nice(0);
        printf("Initial priority of child process: %d\n", initial_nice);

        // Increase the priority (reduce nice value by 5)
        int new_nice = nice(-5);
        if (new_nice == -1 && errno != 0) {
            perror("nice");
            exit(1);
        }

        printf("New priority of child process after nice(-5): %d\n", new_nice);
        
        // Simulate some work
        for (int i = 0; i < 5; i++) {
            printf("Child working...\n");
            sleep(1);
        }
    } else {
        // Parent process
        printf("Parent process with PID %d, waiting for child to complete\n", getpid());
        
        // Wait for child process to complete
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}
