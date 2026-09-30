#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void join(int token)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = token;

    printf("Joined: %d\n", token);
    printf("Front token: %d\n", queue[front]);
}

void serve()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Served: %d\n", queue[front]);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front token: %d\n", queue[front]);
    }
}

int main()
{
    join(101);
    join(102);
    join(103);

    serve();

    join(104);
    join(105);
    join(106);

    serve();
    serve();

    return 0;
}
