#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

void addCritical(Node*& head, int token)
{
    Node* newNode = new Node();

    newNode->token = token;
    newNode->next = head;

    head = newNode;
}

void addRoutine(Node*& head, int token)
{
    Node* newNode = new Node();

    newNode->token = token;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addPriority(Node*& head, int token, int position)
{
    Node* newNode = new Node();

    newNode->token = token;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    addCritical(head, 101);
    display(head);

    addRoutine(head, 102);
    display(head);

    addRoutine(head, 103);
    display(head);

    addPriority(head, 105, 2);
    display(head);

    addCritical(head, 100);
    display(head);

    return 0;
}
