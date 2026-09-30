#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char patient[50];
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void arrive(char name[])
{
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));

    strcpy(newNode->patient, name);
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Arrived: %s\n", name);
    printf("Front patient: %s\n", front->patient);
}

void attend()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Ward is empty\n");
        return;
    }

    temp = front;

    printf("Attended: %s\n", front->patient);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);

    if (front == NULL)
        printf("Ward is empty\n");
    else
        printf("Front patient: %s\n", front->patient);
}

int main()
{
    arrive("Patient1");
    arrive("Patient2");
    arrive("Patient3");

    attend();
    attend();

    arrive("Patient4");

    attend();
    attend();

    return 0;
}
