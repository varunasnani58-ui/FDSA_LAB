#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void addBeginning(char name[])
{
    struct Node *newNode = malloc(sizeof(struct Node));

    strcpy(newNode->song, name);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void addEnd(char name[])
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    strcpy(newNode->song, name);
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(char given[], char name[])
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && strcmp(temp->song, given) != 0)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Song not found\n");
        return;
    }

    newNode = malloc(sizeof(struct Node));

    strcpy(newNode->song, name);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void removeFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void display()
{
    struct Node *temp = head;

    printf("Playlist: ");

    while (temp != NULL)
    {
        printf("%s ", temp->song);
        temp = temp->next;
    }

    printf("\n");
}

void countSongs()
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Number of songs: %d\n", count);
}

int main()
{
    addEnd("Song1");
    display();

    addEnd("Song2");
    display();

    addBeginning("Song0");
    display();

    insertAfter("Song1", "Song1.5");
    display();

    countSongs();

    removeFirst();
    display();

    countSongs();

    return 0;
}
