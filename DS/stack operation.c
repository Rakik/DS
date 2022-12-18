#include <stdio.h>
#define MAXSIZE 5

int top;
int stk[MAXSIZE];
void push(void);
void pop(void);
void display(void);

void main ()
{
    int choice;
    top = -1;

    printf ("STACK OPERATION\n\n");
    while (1)
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default: printf("Invalid Input.");
        }
    }
}

void push ()
{
    int num;
    if (top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        top = top + 1;
        stk[top] = num;
    }
}

void pop ()
{
    int num;
    if (top == - 1)
    {
        printf ("Stack is Empty\n");
    }
    else
    {
        num = stk[top];
        printf ("Popped element is = %d\n", stk[top]);
        top = top - 1;
    }
}

void display ()
{
    int i;
    if (top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = top; i >= 0; i--)
        {
            printf ("%d\n", stk[i]);
        }
    }
    printf ("\n");
}
