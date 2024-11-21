#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{struct data *p; struct node *next;};
struct data{double f; char *s[2];};

struct data* created(){
    struct data *tmp = (struct data *)malloc(sizeof(struct data));
    printf("double number: ");
    scanf("%lf", &(tmp->f));
    printf("two characters: ");
    tmp->s[0] = (char *)malloc(10 * sizeof(char));
    tmp->s[1] = (char *)malloc(10 * sizeof(char));
    scanf("%s %s", tmp->s[0], tmp->s[1]);
    return tmp;
}

struct node* createn(int n){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    struct node *ans = tmp;
    tmp->p = created();
    for (int i = 1; i < n; ++i) {
        tmp->next = (struct node *)malloc(sizeof(struct node));
        tmp = tmp->next;
        tmp->p = created();
    }
    tmp->next = NULL;
    return ans;
}

struct data* copyd(struct data *p){
    struct data *tmp = (struct data *)malloc(sizeof(struct data));
    tmp->f = p->f;
    tmp->s[0] = (char *)malloc(10 * sizeof(char));
    tmp->s[1] = (char *)malloc(10 * sizeof(char));
    strcpy(tmp->s[0], p->s[0]);
    strcpy(tmp->s[1], p->s[1]);
    return tmp;
}

struct node* copyn(struct node *head1){
    if (head1 == NULL){
       return 0;
    }
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *ans = head2;
    head2->p = copyd(head1->p);
    head2->next = NULL;
    head1 = head1->next;
    while (head1 != NULL){
        head2->next = (struct node *)malloc(sizeof(struct node));
        head2 = head2->next;
        head2->p = copyd(head1->p);
        head2->next = NULL;
        head1 = head1->next;
    }
    return ans;
}

void printl(struct node *head){
    while (head != NULL){
        printf("%lf %s %s\n", head->p->f, head->p->s[0], head->p->s[1]);
        head = head->next;
    }
}

int main(void){
    int n;
    printf("number of items: ");
    scanf("%d", &n);
    struct node *head1 = createn(n);
    struct node *head2 = copyn(head1);
    printf("\n");
    printl(head2);
    return 0; 
}
