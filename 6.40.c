#include <stdio.h>
#include <stdlib.h>

struct node
{
    char *data;
    struct node *next;
};
int add(struct node *head, char *elem)
{
    int a = 0;
    struct node *tmp = head;
    while (head->data != ".")
    {
        if (head->data == elem) a = 1;
        head = head->next;
    }
    head = tmp;
    return a;
}

void makel(struct node *head1, struct node *head2, struct node *head3){
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    struct node *tmp3 = head3;
    
    while (head1->data != ".")
    {
        if (add(head2, head1->data) == 0)
        {
            head3->data = head1->data;
            head3->next = (struct node *)malloc(sizeof(struct node));
            head3 = head3->next;   
        }
        head1 = head1->next;
    }
    head1 = tmp1;
    head2 = tmp2;
    while (head2->data != ".")
    {
        if (add(head1, head2->data) == 0)
        {
            head3->data = head2->data;
            head3->next = (struct node *)malloc(sizeof(struct node));
            head3 = head3->next;   
        }
        head2 = head2->next;
    }
    head3->next = (struct node *)malloc(sizeof(struct node));
    head3->data = ".";
    head3->next = NULL;
    head1 = tmp1;
    head2 = tmp2;
    head3 = tmp3;
}

void printl(struct node *head)
{
    struct node *tmp = head;
    while (head->data != "."){
        printf("%s\n", head->data);
        head= head->next;
    }
    head = tmp;
}

int main(void){
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp1 = head1;
    
    printf("first list: \n"); 
    head1->data = "one";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;
    head1->data = "two";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;  
    head1->data = "three";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;   
    head1->data = ".";
    head1->next = NULL;
    head1 = tmp1;
    printl(head1);
    
    printf("\nsecond list: \n");
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp2 = head2;
    head2->data = "two";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;   
    head2->data = "three";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next; 
    head2->data = "four";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;
    head2->data = ".";
    head2->next = NULL;
    head2 = tmp2;
    printl(head2);
    
    printf("\nthird list: \n");
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp3 = head3;
    makel(head1, head2, head3);
    printl(head3);
    
    return 0;
}
