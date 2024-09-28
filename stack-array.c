#include <stdio.h>

int main()
{

    int a[5];
    int top = -1;
    int i, ch;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (top == 4)
            {
                printf("\nStack is overflow!");
            }
            else
            {
                top = top + 1;
                printf("\nEnter the element: ");
                scanf("%d", &a[top]);
            }
            break;

        case 2:
            if (top == -1)
            {
                printf("\nStack Underflow!");
            }
            else
            {
                printf("\nThe element popped is %d ",a[top]);
                top = top - 1;
            }
            break;
        case 3:
            if (top == -1)
            {
                printf("\nStack is Empty!");
            }
            else
            {
                for (i = 0; i <= top; i++)
                {
                    printf("%d\n", a[i]);
                }
                printf("\n");
            }

            break;
        case 4:
            printf("Exited..!");

        default:
            printf("\nInvalid Choice!");
            break;
        }
    } while (ch != 4);

    return 0;
}
