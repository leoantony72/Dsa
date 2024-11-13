#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};

struct node* createNode(int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    return p;
}

void insert(struct node** head, int data){
    struct node* ptr = *head;
    struct node* p =  createNode(data);
    if(*head==NULL){
        *head = p;
        return;
    }
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link= p;
}
void display(struct node* head){
    struct node* ptr = head;
    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void sumAndaverage(struct node* head,int n){
    struct node* ptr = head;
    int sum =0;
    int avg=0;
    while (ptr!=NULL)
    {
        sum=sum+ptr->data;
        ptr=ptr->link;
    }
    avg=sum/n;

    printf("Sum =%d | Avg =%d \n",sum,avg);
}

void main(){
    struct node* head = NULL;
    int  i,n,data;
    printf("enter the number of values to insert:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head,data);
    }

    display(head);
    sumAndaverage(head,n);
}