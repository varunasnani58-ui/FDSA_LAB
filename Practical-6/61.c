#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int tray)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = tray;

    printf("Placed tray: %d\n", tray);
    printf("Top tray: %d\n", stack[top]);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Taken tray: %d\n", stack[top]);
    top--;

    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top tray: %d\n", stack[top]);
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    push(40);

    pop();
    pop();
    pop();

    return 0;
}
