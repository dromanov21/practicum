#include <stdio.h>
#include <stdlib.h>

struct queue{double data; struct queue *next;};

void putqueue(struct queue **head, double value)
{
    struct queue *tmp = *head;
    if ((*head) == NULL)
    {
        *head = (struct queue *)malloc(sizeof(struct queue));
        (*head)->next = NULL;
        (*head)->data = value;
    } 
    else
    {
    while ((*head)->next != NULL) (*head) = (*head)->next;
    (*head)->next = (struct queue *)malloc(sizeof(struct queue));
    (*head)->next->data = value;
    (*head)->next->next = NULL;
    (*head) = tmp;
    }
}

int getqueue(struct queue **head){
    double value;
    value = (*head)->data;
    (*head) = (*head)->next;
    return value;
}

int sizequeue(struct queue *head)
{
    int n = 0;
    for(; head != NULL; head = head->next){
        ++n;
    }
    return n;
}


void deleteq(struct queue *q)
{
    struct queue *tmp = q;
    struct queue *n;
    while (q != NULL)
    {
        n = q;
        q = q->next;
        free(n);
    }
    q = tmp;
}

void printl(struct queue *head)
{
    struct queue *tmp = head;
    printf("\n");
    printf("Your list: \n");
    while (head != NULL)
    {
        printf("%lf\n", head->data);
        head = head->next;
    }
    head = tmp;
}

int main(void){
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    struct queue *tmp = head;
    head = NULL;
    
    double value;
    printf("Enter first element: ");
    scanf("%lf", &value);  
    putqueue(&head, value);
    printf("Enter second element: ");
    scanf("%lf", &value);  
    putqueue(&head, value);
    printf("Enter third element: ");
    scanf("%lf", &value);  
    putqueue(&head, value);
    printl(head);
    int l = sizequeue(head);
    printf("\n");
    printf("Size of list: %d", l);
    printf("\n");
    int k = getqueue(&head);
    printl(head);
    printf("\n");
    printf("Received element: ");
    printf("%d", k);
    return 0;
}
