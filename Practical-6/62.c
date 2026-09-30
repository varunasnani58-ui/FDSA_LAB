#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *next;
};

struct Node *top = NULL;

void visit(char page[])
{
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->next = top;
    top = newNode;

    printf("Visited: %s\n", page);
    printf("Current page: %s\n", top->page);
}

void back()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("No history left\n");
        return;
    }

    temp = top;
    top = top->next;

    printf("Back from: %s\n", temp->page);
    free(temp);

    if (top == NULL)
        printf("No history left\n");
    else
        printf("Current page: %s\n", top->page);
}

int main()
{
    visit("Google");
    visit("YouTube");
    visit("Wikipedia");

    back();
    back();

    back();
    back();

    return 0;
}
