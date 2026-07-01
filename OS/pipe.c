#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid;
    char writeMsg[100], readMsg[100];

    // Create two pipes for full duplex communication
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // ---------- CHILD PROCESS ----------
    else if (pid == 0) {
        close(fd1[1]); // close write end of first pipe (parent -> child)
        close(fd2[0]); // close read end of second pipe (child -> parent)

        read(fd1[0], readMsg, sizeof(readMsg));
        printf("\n[Child] Received from Parent: %s\n", readMsg);

        // Count characters, words, lines
        int chars = 0, words = 0, lines = 0, in_word = 0;
        for (int i = 0; readMsg[i] != '\0'; i++) {
            chars++;
            if (readMsg[i] == '\n')
                lines++;
            if (isspace(readMsg[i]))
                in_word = 0;
            else if (!in_word) {
                in_word = 1;
                words++;
            }
        }

        sprintf(writeMsg, "Characters: %d, Words: %d, Lines: %d", chars, words, lines);

        write(fd2[1], writeMsg, strlen(writeMsg) + 1);
        printf("[Child] Sent analysis back to Parent.\n");

        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    }

    // ---------- PARENT PROCESS ----------
    else {
        close(fd1[0]); // close read end of first pipe
        close(fd2[1]); // close write end of second pipe

        printf("Enter a string (or sentence): ");
        fgets(writeMsg, sizeof(writeMsg), stdin);
        writeMsg[strcspn(writeMsg, "\n")] = '\0'; // remove newline

        write(fd1[1], writeMsg, strlen(writeMsg) + 1);
        printf("[Parent] Sent message to Child.\n");

        read(fd2[0], readMsg, sizeof(readMsg));
        printf("[Parent] Received from Child: %s\n", readMsg);

        close(fd1[1]);
        close(fd2[0]);
    }

    return 0;
}
