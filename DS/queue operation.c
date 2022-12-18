#include <stdio.h>
#define MAX 50

int q_array[MAX];
int rear = - 1;
int front = - 1;

void insert();
void deletee();
void display();
void main()
{
    int choice;
    while (1)
    {
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Display \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                    insert();
                    break;
            case 2:
                    deletee();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
}
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        q_array[rear] = add_item;
    }
}

void deletee()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q_array[front]);
        front = front + 1;
    }
}
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", q_array[i]);
        printf("\n");
    }
}
