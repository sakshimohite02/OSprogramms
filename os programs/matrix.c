#include <stdio.h>

void calculateNeed(int processes[], int max[][10], int allot[][10], int need[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

void displayMatrix(int matrix[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;  // m = number of processes, n = number of resources

    // Accept number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resources: ");
    scanf("%d", &n);

    int processes[m], max[m][10], allot[m][10], need[m][10];

    // Input the allocation matrix
    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Input the maximum matrix
    printf("Enter the Maximum matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Calculate the Need matrix
    calculateNeed(processes, max, allot, need, m, n);

    // Display the Need matrix
    printf("Need matrix:\n");
    displayMatrix(need, m, n);

    return 0;
}
