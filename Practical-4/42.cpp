#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

void insert(Node*& head, int x)
{
    Node* n = new Node{x, NULL};

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node* t = head;

    while (t->next != NULL)
        t = t->next;

    t->next = n;
}

void deleteValue(Node*& head, int x)
{
    if (head == NULL)
        return;

    if (head->token == x)
    {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }

    Node* t = head;

    while (t->next != NULL && t->next->token != x)
        t = t->next;

    if (t->next != NULL)
    {
        Node* p = t->next;
        t->next = p->next;
        delete p;
    }
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->token << " ";
        head = head->next;
    }

    cout << endl;
}

void reversePrint(Node* head)
{
    if (head == NULL)
        return;

    reversePrint(head->next);
    cout << head->token << " ";
}

int main()
{
    Node* head = NULL;

    insert(head, 101);
    insert(head, 102);
    insert(head, 103);
    insert(head, 104);

    cout << "Queue: ";
    display(head);

    deleteValue(head, 102);

    cout << "After deletion: ";
    display(head);

    cout << "Reverse: ";
    reversePrint(head);

    return 0;
}
