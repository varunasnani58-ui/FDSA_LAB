#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int student;
    struct Node *next;
};

struct Node *head = NULL;

void join(int student)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->student = student;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void leave(int student)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL)
    {
        printf("Circle is empty\n");
        return;
    }

    if (head->student == student)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }

        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;

        temp = head;
        head = head->next;

        free(temp);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head && temp->student != student)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("Student not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Circle is empty\n");
        return;
    }

    temp = head;

    printf("Circle: ");

    do
    {
        printf("%d ", temp->student);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

int main()
{
    join(1);
    display();

    join(2);
    display();

    join(3);
    display();

    leave(2);
    display();

    join(4);
    display();

    leave(1);
    display();

    return 0;
}
