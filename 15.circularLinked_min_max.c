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
    //p->link=*head;
    if(*head==NULL){
        *head = p;
        p->link=*head;
        return;
    }
    while(ptr->link!=*head){
        ptr=ptr->link;
    }
    ptr->link= p;
    p->link=*head;
}
//no need for this function
void display(struct node* head){
    struct node* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do{
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }while (ptr!=head);
    printf("\n");
}

void minandmax(struct node* head){
    int min = head->data;
    int max = head->data;
    struct node* ptr = head;


    do{
        if(ptr->data < min){
            min=ptr->data;
        }else if(ptr->data > max){
            max=ptr->data;
        }
        ptr=ptr->link;
    }while(ptr!=head);

    printf("min =%d | max=%d \n",min,max);
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
    minandmax(head);
}