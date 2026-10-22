#include <stdio.h>
#define SIZE 10

int main() {
    int table[SIZE];
    int n, number, index, i;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter registration number: ");
        scanf("%d", &number);

        index = number % SIZE;

        int count = 0;

        while (table[index] != -1 && count < SIZE) {
            index = (index + 1) % SIZE;
            count++;
        }

        if (count == SIZE) {
            printf("Parking lot is full!\n");
        } else {
            table[index] = number;
            printf("Vehicle parked at slot %d\n", index);
        }
    }

    printf("\nFinal Parking Slots:\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, table[i]);
    }

    return 0;
}
