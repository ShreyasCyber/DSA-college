#include <stdio.h>

int main()
{
    int a[5];
    int ch, i;
    int front = -1, rear = -1;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (rear == 4)
            {
                printf("\nQueue Overflow!");
            }
            else
            {
                if (front == -1)
                {
                    front = front + 1;
                    rear = rear + 1;
                }
                else
                {
                    rear = rear + 1;
                }
                printf("\nEnter enqueue element: ");
                scanf("%d", &a[rear]);
            }

            break;
        case 2:
            if (front == -1)
            {
                printf("\nQueue is empty!");
            }
            else
            {
                for (i = front; i <= rear; i++)
                {
                    printf("%d ", a[i]);
                }
            }
            break;

        case  3:
            if (front == -1)
            {
                printf("\nQueue Underflow");
            }
            else
            {
                printf("\n%d is dequeued.",a[front]);
                front +=1;

                if (front > rear)
                {
                    front = -1;
                    rear = -1;
                }
                
            }

        default:
            break;
        }
    } while (ch != 4);

    return 0;
}