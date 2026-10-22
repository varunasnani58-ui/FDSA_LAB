#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int code;
    struct Node *next;
};

struct Node *table[SIZE];

void insert(int code) {
    int index = code % SIZE;

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->code = code;
    newNode->next = table[index];
    table[index] = newNode;

    printf("Book %d added to shelf %d\n", code, index);
}

void display() {
    int i;
    struct Node *temp;

    printf("\nFinal Shelf Contents:\n");

    for (i = 0; i < SIZE; i++) {
        printf("Shelf %d: ", i);

        temp = table[i];

        while (temp != NULL) {
            printf("%d -> ", temp->code);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int n, code;

    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter book code: ");
        scanf("%d", &code);
        insert(code);
    }

    display();

    return 0;
}
