#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

typedef struct stack STACK;

STACK *top = NULL, *p, *q;

void push();
void pop();
void traverse();
void tos();

int main()
{

    int ch;

    do
    {
        printf("\n1.PUSH\n2.POP\n3.Traverse\n4.TOS\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            tos();
            break;
        case 5:
            printf("\nExiting..");
        default:
            printf("\nInvalid choice..");
            break;
        }
    } while (ch != 5);

    return 0;
}

void push()
{
    p = (STACK *)malloc(sizeof(STACK));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);

    if (top == NULL)
    {
        p->next = NULL;
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        p = top;
        top = top->next;
        printf("\n%d is popped.",p->data);
        free(p);
    }
}

void traverse()
{
    if (top == NULL)
    {
        printf("\nStack is empty!");
    }
    else
    {
        p = top;

        while (p != NULL)
        {
            printf("\n%d", p->data);
            p = p->next;
        }
    }
}

void tos(){
    if (top == NULL)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nThe top is %d",p->data);
    }
}