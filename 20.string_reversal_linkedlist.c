#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(char data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

void insert(struct node** head, char data){
    struct node* ptr = *head;
    struct node* p =  createNode(data);
    if(*head==NULL){
        *head = p;
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next= p;
    p->prev=ptr;
}

void reverse(struct node* head){
    struct node* ptr = head;
    char rev[100];
    int i=0;
    if(head==NULL){
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(ptr!=NULL){
        rev[i]=ptr->data;
        ptr=ptr->prev;
        i++;
    }
    rev[i]='\0';
    printf("%s \n",rev);
}

void main(){
    struct node* head = NULL;
    int  i,n;
    char name[100];
    printf("enter the string to reverse:");
    scanf("%s",name);
    for(i=0; name[i]!='\0';i++){
        insert(&head,name[i]);
    }
    reverse(head);
}