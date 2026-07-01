#include <stdio.h>

int main() {
    int no_of_frames, no_of_pages;
    int frames[10], pages[30], temp[10];
    int flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

    // Input number of frames and pages
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames to -1 (empty)
    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    // Optimal Page Replacement Logic
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if page already exists in a frame (HIT)
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not found (MISS) and an empty frame exists
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        // If page not found and no empty frame available
        if (flag2 == 0) {
            flag3 = 0;

            // For each frame, find the next use of the page
            for (j = 0; j < no_of_frames; ++j) {
                temp[j] = -1;
                for (k = i + 1; k < no_of_pages; ++k) {
                    if (frames[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            // Find frame not used in future
            for (j = 0; j < no_of_frames; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            // If all pages are going to be used again, replace the farthest one
            if (flag3 == 0) {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            // Replace the page at position 'pos'
            frames[pos] = pages[i];
            faults++;
        }

        // Display current frame status
        printf("\n");
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%d\t", frames[j]);
            else
                printf("-\t");
        }
    }

    // Print total faults
    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
