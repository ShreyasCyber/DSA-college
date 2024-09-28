#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} NODE;

NODE *start = NULL, *p, *q;
int loc, i;

void createAtStart();
void createAtEnd();
void createAtGiveLocation();
void deleteAtStart();
void deleteAtEnd();
void deleteAtGiveLocation();
void traverse();

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
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtGiveLocation();
            break;
        case 7:
            traverse();
            break;
        case 8:
            printf("\nExit");
        default: 
        
        printf("\nInvalid choice");
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
    }
    else
    {
        q = start;

        while (q->next != NULL)
        {
            q = q->next;
        }

        q->next = p;
        p->next = NULL;
    }
}

void createAtGiveLocation()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the Data: ");
    scanf("%d", &p->data);
    printf("\nEnter the location: ");
    scanf("%d", &loc);

    if (start == NULL)
    {
        if (loc == 1)
        {
            p->next = NULL;
            start = p;
        }
        else
        {
            printf("Invalid location!");
            free(p);
        }
    }
    else
    {
        if (loc == 1)
        {
            p->next = start;
            start = p;
        }
        else
        {
            i = 1;
           q = start;

            while (i < loc - 1 && q->next != NULL)
            {
                q = q->next;
                i++;
            }

            if (q != NULL)
            {
                p->next = q->next;
                q->next = p;
            }
            else
            {
                printf("Invalid location!");
                free(p);
            }
        }
    }
}

void deleteAtStart()
{
    if (start == NULL)
    {
        printf("Delete Function not be performed!");
    }
    else
    {
        p = start;
        start = start->next;
        printf("Deleted element: %d\n", p->data);
        free(p);
    }
}

void deleteAtEnd()
{
    if (start == NULL)
    {
        printf("Delete Function not be performed!");
    }
    else if (start->next == NULL)
    {
        p = start;
        printf("\nDeleted item: %d\n", p->data);
        start = NULL; // start->next;
        free(p);
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }

        q->next = NULL;
        printf("\nDeleted item: %d\n", p->data);
        free(p);
    }
}

void deleteAtGiveLocation()
{
    if (start == NULL)
    {
        printf("Delete Function not be performed!");
    }
    else
    {
        printf("\nEnter the location to delete: ");
        scanf("%d", &loc);

        if (loc == 1)
        {
            p = start;
            start = start->next;
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

            if (p != NULL)
            {
                q->next = p->next;
                printf("\nDeleted item: %d\n", p->data);
                free(p);
            }
            else
            {
                printf("Invalid location!");
            }
        }
    }
}

void traverse()
{
    if (start == NULL)
    {
        printf("List is empty!");
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
