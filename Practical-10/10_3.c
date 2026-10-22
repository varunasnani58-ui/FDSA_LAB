#include <stdio.h>
#define SIZE 10

int main() {
    int table[SIZE];
    int n, id, h1, h2, index, i;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter student ID: ");
        scanf("%d", &id);

        h1 = id % SIZE;
        h2 = 7 - (id % 7);

        int j;

        for (j = 0; j < SIZE; j++) {
            index = (h1 + j * h2) % SIZE;

            if (table[index] == -1) {
                table[index] = id;
                printf("Student %d stored at slot %d\n", id, index);
                break;
            }
        }

        if (j == SIZE)
            printf("Hash table is full! ID %d not inserted.\n", id);
    }

    printf("\nFinal Hash Table:\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, table[i]);
    }

    return 0;
}
