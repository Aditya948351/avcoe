#include <stdio.h>

int np, nr;                     // Number of processes and resources
int allocation[10][10], max[10][10], need[10][10], avail[10];

// Function to read a matrix
void readMatrix(int matrix[10][10]) {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10]) {
    for (int i = 0; i < np; i++) {
        printf("\nP%d\t", i);
        for (int j = 0; j < nr; j++) {
            printf("%d\t", matrix[i][j]);
        }
    }
    printf("\n");
}

// Function to calculate the Need matrix
void calculateNeed() {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to execute Banker’s Algorithm
void bankersAlgorithm() {
    int finish[10] = {0};   // To track if process is completed
    int safeSeq[10];        // To store safe sequence
    int work[10];           // Temporary copy of available
    int count = 0;          // Number of processes finished

    // Initialize work with available resources
    for (int i = 0; i < nr; i++)
        work[i] = avail[i];

    while (count < np) {
        int found = 0;
        for (int i = 0; i < np; i++) {
            if (finish[i] == 0) {  // If process not yet finished
                int j;
                for (j = 0; j < nr; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == nr) { // If all needs can be satisfied
                    for (int k = 0; k < nr; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {  // No process could be executed in this round
            printf("\nSystem is in DEADLOCK state!\n");
            return;
        }
    }

    // If all processes finished successfully
    printf("\nSystem is in SAFE STATE.\nSafe Sequence: ");
    for (int i = 0; i < np; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
}

// Main function
int main() {
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter number of resources: ");
    scanf("%d", &nr);

    printf("\nEnter Allocation Matrix:\n");
    readMatrix(allocation);

    printf("\nEnter Maximum Requirement Matrix:\n");
    readMatrix(max);

    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < nr; i++)
        scanf("%d", &avail[i]);

    printf("\n--- Input Data ---\n");
    printf("\nAllocation Matrix:");
    displayMatrix(allocation);

    printf("\nMaximum Requirement Matrix:");
    displayMatrix(max);

    printf("\nAvailable Resources: ");
    for (int i = 0; i < nr; i++)
        printf("%d ", avail[i]);
    printf("\n");

    calculateNeed();
    printf("\nNeed Matrix:");
    displayMatrix(need);

    bankersAlgorithm();

    return 0;
}
