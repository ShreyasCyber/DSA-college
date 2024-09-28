#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} NODE;

NODE *start = NULL, *p, *q, *last = NULL;

void createAtStart();
void createAtEnd();
void traverse();
void deleteAtStart();
int main()
{
    int ch;
    do
    {

        printf("1. Create at start \n2. create at end\n3. create at given location\n4. delete at start\n5. delete at end\n6. delete at given location\n7. tranvers\n8. exit\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            createAtStart();
            break;
        case 2:
            createAtEnd();
            break;
        case 3:
            createAtGiveLocation();
            break;
        case 4:
            deleteAtStart();
            break;
        case 7:
            traverse();
            break;
        case 8:
            printf("\nExit");
        default:
            break;
        }
    } while (ch != 8);
    return 0;
}

void createAtStart()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the Data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        start = p;
        last = p;
    }
    else
    {
        p->next = start;
        start = p;
    }
}

void createAtEnd()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        start = p;
        last = p;
    }
    else
    {
        last->next = p;
        p->next = NULL;
        last = p;
    }
}
void traverse()
{
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
    }
}

void deleteAtStart()
{
    if (start == NULL)
    {
        printf("\nThe delete function cannot performed!");
    }
    else if (start->next == NULL)
    {
        p = start;
        start = NULL;
        last = NULL;
        printf("The delete node is %d", p->data);
        free(p);
    }
    else
    {
        p = start;
        start = start->next;
        printf("The delete node is %d", p->data);
        free(p);
    }
}

void deleteAtGiveLocation()
{
    int loc, i;

    if (start == NULL)
    {
        printf("Delete function cannot be performed! The list is empty.\n");
    }
    else
    {
        printf("\nEnter the location to delete: ");
        scanf("%d", &loc);

        if (loc == 1) // Deleting the first node
        {
            p = start;
            start = start->next;

            if (start == NULL) // List becomes empty after deletion
            {
                last = NULL; // Update last pointer
            }

            printf("\nDeleted item: %d\n", p->data);
            free(p);
        }
        else
        {
            i = 1;
            p = start;

            while (i < loc && p->next != NULL)
            {
                q = p;
                p = p->next;
                i++;
            }

            if (i == loc) // If the location is valid
            {
                q->next = p->next;

                if (p->next == NULL) // If the deleted node is the last node
                {
                    last = q; // Update the last pointer to the previous node
                }

                printf("\nDeleted item: %d\n", p->data);
                free(p);
            }
            else
            {
                printf("Invalid location!\n");
            }
        }
    }
}
