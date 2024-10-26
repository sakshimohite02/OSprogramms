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
        printf("Child process (PID: %d) executing 'ls' command...\n", getpid());
        
        // Use execl to execute the 'ls' command
        execl("/bin/ls", "ls", NULL);
        
        // If execl() fails
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process (PID: %d) going to sleep...\n", getpid());
        
        sleep(5);  // Sleep for 5 seconds
        printf("Parent process (PID: %d) awake!\n", getpid());
    }

    return 0;
}
