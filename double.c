#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
NODE *start = NULL, *p, *q;
int loc, i;

void addANode()
{
    p=(NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start->prev = p;
        start = p;
        p->prev = NULL;
    }
}

void addAtEnd()
{
    p=(NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        q = start;
        while(q->next != NULL)
        {
            q = q->next;
        }

        q->next = p;
        p->prev = q;
        p->next = NULL;

    }
        
}

void addAtLocation()
{
    p = (NODE *)sizeof(NODE);
    printf("\nEnter the data: ");
    scanf("%d", &p->data);
    printf("\nEnter the location: ");
    scanf("%d", &loc);

    if (start == NULL)
    {
        if (loc == 1)
        {
            p->next = NULL;
            p->prev= NULL;
            start = p;
        }
        else
        {
            printf("\nInvalid location");
            free(p);
        }
    }
    else
    {
        if (loc == 1)
        {
            p->next = start;
            start->prev = p;
            p->prev = NULL;
            start = p;
        }
        else
        {
            i = 1;
            q = start;
            while (i < loc - 1 && q!= NULL)
            {
                q = q->next;
                i++;
            }
            if (q!=NULL)
            {
                p->next = q->next;
                if (q->next!= NULL)
                {
                    q->next->prev = p;
                }
                p->prev = q;
                q->next = p;
            }
            else
            {
                printf("\nInvalid location");
                free(p);
            }
        }
    }
    
}

void deleteANode() {
    if (start == NULL)
    {
        printf("\nLL is empty!");
    }
    else
    {
        p = start;
        start = start-> next;
        if (p->next != NULL)
        {
            p->next->prev = NULL;
        }
        printf("\nDeleted node is %d", p->data);
        free(p);
    }
    
}

void deleteAtEnd() {
    if (start == NULL)
    {
        printf("\nLL is empty!");
    }
    else
    {
        p = start;
        while (p->next != NULL) 
        {
            p = p->next;
        }

        q = p->prev;
        q -> next = NULL;
        printf("\nDeleted node is %d", p->data);
        free(p);
    }
    
}

void deleteAtLocation() {}

void traverse()
{
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Add a node\n2.add at end\n3.add at given location\n4.Delete a node\n5.Delete at end\n6.Delete at given location\n7.Traverse");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addANode();
            break;
        case 2:
            addAtEnd();
            break;
        case 3:
            addAtLocation();
            break;
        case 4:
            deleteANode();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtLocation();
            break;
        case 7:
            traverse();
        default:
            break;
        }
    } while (ch != 8);

    return 0;
}
