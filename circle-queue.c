#include <stdio.h>

int main()
{

    int front = -1, rear = -1;
    int ch;
    int a[5];

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (front == (rear + 1) % 5)
            {
                printf("\nQueue Overflow");
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear = (rear + 1) % 5;
                }
                printf("\nEnter the data: ");
                scanf("%d", a[rear]);
            }

            break;
            
        case 2:
            if (front == -1)
            {
                printf("\nQueue is empty!");
            }
            else
            {
                printf("\n%d is Dequeued.", a[front]);
                front = (front + 1) % 5;

                if (front == (rear + 1) % 5)
                {
                    front = -1;
                    rear = -1;
                }
            }
            break;

        case 3:
            if (front == -1)
            {
                printf("\nQueue is empty");
            }
            else
            {
                for (int i = front; i < rear; i = (i + 1) % 5)
                {
                    printf("%d ", a[i]);
                }
            }
            break;
        case 4:
            printf("\nExiting...");
        default:
            printf("\nInvalid choice.");
            break;
        }
    } while (ch != 5);

    return 0;
}
