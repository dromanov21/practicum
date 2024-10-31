#include <stdio.h>
#include <stdlib.h>

struct node{
    double data;
    struct node *next;
};

void change_first_last(struct node *head){
    struct node *tmp = head;
    struct node *last;
    double first;
    
    first = head->data;
    while (head->data != 0){
        last = head;
        head = head->next;
    }
    head = tmp;
    head->data = last->data;
    last->data = first;
}

int main(void){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tmp = head;
    
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
    change_first_last(head);
    printf("\n");
    printf("list after change firat and last node: \n");
    while (head->data != 0){
        printf("%lf\n", head->data);
        head = head->next;
    }
    return 0;
}
