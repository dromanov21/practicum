#include <stdio.h>
#include <stdlib.h>

struct node{
    double data;
    struct node *next;
};

void change_first_last(struct node *head, double same){
    struct node *tmp = head;
    struct node *q;
    
    while (head->data != 0)
    {
        if (head->data == same) 
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = same;
            q->next = head->next;
            head->next = q;
            head = head->next->next;
        }
        else head = head->next;
    }
    head = tmp;
}

int main(void){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tmp = head;
    
    printf("Enter elements of the list: ");
    scanf("%lf", &(head->data));
    while (head->data != 0){
        head->next = (struct node *)malloc(sizeof(struct node));
        head = head->next;
        scanf("%lf", &head->data);
    }
    head->next = NULL;
    head = tmp;
    printf("original list: \n");
    while (head->data != 0){
        printf("%lf\n", head->data);
        head = head->next;
    }
    head = tmp;
    double k;
    printf("Enter the element you want to duplicate: ");
    scanf("%lf", &k);
    change_first_last(head, k);
    printf("\n");
    printf("list after change first and last node: \n");
    while (head->data != 0){
        printf("%lf\n", head->data);
        head = head->next;
    }
    return 0;
}
