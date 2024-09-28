#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *start = NULL, *last = NULL, *p, *q;
int i, loc;

void insertAtStart()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = p;
        start = p;
        last = p;
    }
    else
    {
        p->next = start;
        start = p;
        last->next = p;
    }
}

void insertAtEnd()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = p;
        start = p;
        last = p;
    }
    else
    {
        p->next = start;
        last->next = p;
        last = p;
    }
}

void insertAtGivenIndex()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    printf("\nEnter the index: ");
    scanf("%d", &loc);

    if (start == NULL)
    {
        if (loc == 1)
        {
            p->next = p;
            start = p;
            last = p;
        }
        else
        {
            printf("\nInvalid Location!");
            free(p);
        }
    }
    else
    {
        if (loc == 1)
        {
            p->next = start;
            last->next = p;
            start = p;
        }
        else
        {
            i = 1;
            q = start;
            while (i < loc - 1 && q->next != start)
            {
                q = q->next;
                i++;
            }

            if (q->next == start && loc - 1 == i)
            {
                p->next = start;
                q->next = p;
                last = p;
            }
            else if (i == loc - 1)
            {
                p->next = q->next;
                q->next = p;
            }
            else
            {
                printf("\nInvalid location!");
                free(p);
            }
        }
    }
}

void deleteFromStart()
{
    if (start == NULL)
    {
        printf("\nDelete function not performed!");
        free(p);
    }
    else
    {
        last->next = start;
        start = last;
        printf("\nDelete element: %d", p->data);
        free(p);
    }
}

void deleteFromEnd() {}

void deleteFromGivenIndex() {}

void display()
{
    if (start == NULL)
    {
        printf("\nThe list is empty now!");
    }
    else
    {
        q = start;
        do
        {
            printf("%d ", q->data);
            q = q->next;
        } while (q != start);
    }
}

int main()
{

    int ch;

    do
    {
        printf("\n1. Insert at start\n2. Insert at end\n3. Delete from start\n4. Delete from end\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertAtStart();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtGivenIndex();
            break;
        case 4:
            deleteFromStart();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteFromGivenIndex();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.");
        }
    } while (ch != 8);

    return 0;
}
