#include <stdio.h>

void calculateMinResources(int processes[], int m, int n, int max[][10], int allot[][10]) {
    int totalMaxDemand[10] = {0};  // Array to store total maximum demand for each resource
    int totalAllocated[10] = {0};   // Array to store total allocated resources

    // Calculate total maximum demand and total allocated resources
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            totalMaxDemand[j] += max[i][j];
            totalAllocated[j] += allot[i][j];
        }
    }

    // Calculate minimum resources needed to avoid deadlock
    printf("Minimum resources needed to avoid deadlock:\n");
    for (int j = 0; j < n; j++) {
        int minResourcesNeeded = (totalMaxDemand[j] - totalAllocated[j]) + 1;
        printf("Resource %d: %d\n", j + 1, minResourcesNeeded);
    }
}

int main() {
    int m, n;  // m = number of processes, n = number of resources

    // Accept number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resources: ");
    scanf("%d", &n);

    int processes[m], max[m][10], allot[m][10];

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

    // Calculate minimum resources needed to avoid deadlock
    calculateMinResources(processes, m, n, max, allot);

    return 0;
}
