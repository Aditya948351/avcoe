#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, head, total = 0;
    int requests[100], visited[100] = {0};

    // Input number of disk requests
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    // Input disk requests
    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    // Input initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\n--- SSTF (Shortest Seek Time First) Disk Scheduling ---\n");
    printf("Sequence: %d", head);

    int count = 0;
    while (count < n) {
        int min = 9999, index = -1;

        // Find the closest unvisited request
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                int dist = abs(head - requests[i]);
                if (dist < min) {
                    min = dist;
                    index = i;
                }
            }
        }
        // Move the head to the nearest request
        total += min;
        head = requests[index];
        visited[index] = 1;
        count++;

        printf(" -> %d", head);
    }

    printf("\nTotal head movement: %d\n", total);
    return 0;
}
