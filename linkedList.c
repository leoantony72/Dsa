#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *link;
};

struct Node* createNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        printf("alloc failed");
        exit(1);
    }
    p->data = data;
    p->link=NULL;
    return p;
}

void insertAtBeginning(struct Node* head){
   int data;
   scanf("%d",&data);
   struct Node *p=createNode(data);
   p->link = head;
   head = p;
}

void insertAtEnd(struct Node** head){
   int data;
   scanf("%d",&data);
   struct Node *p = createNode(data) ;
   if(*head == NULL){
     *head = p;
     return;
   }
   struct Node* temp = *head;
   while(temp->link != NULL){
     temp = temp->link;
   }
   temp->link=p;
}



void printList(struct Node* node) {
    while (node!=NULL) {
        printf("%d -> ", node->data);
        node = node->link;
    }
    printf("null\n");
}

void insertAtPosition(struct Node* head){
   int data,position,i;
   printf("enter data to insert:");
   scanf("%d",&data);
   printf("enter position to insert into:");
   scanf("%d",&position);
   if(position < 0){
    printf("invalid position\n");
    return;
   }
   if(position == 0){
    insertAtBeginning(head);
    return;
   }
    struct Node* temp =head;
   for(i=0;i<position -1;i++){
    if(temp==NULL){
        printf("index out of bounds");
        return;
    }
    temp = temp->link;
   }

   struct Node* p = createNode(data);
   p->link=temp->link;
   temp->link=p;
}


void main(){
    struct Node* head =NULL;
    int act;
    do{
        printf("1.insert at beginning\t2.insert at end\t3.insert at position\t4.delete from beginning\t5.delete from end\t6.insert at position\t7.print list\t8. End\n");
        scanf("%d",&act);
        switch(act){
            case 1: insertAtBeginning(head); break;
            case 2: insertAtEnd(&head); break;
            //case 3: insertAtPosition();break;
           // case 4: deleteFromBeginning();break;
            //case 5: deleteFromEnd();break;
           // case 6: deleteFromPosition();break;
            case 7: printList(head);break;
            case 8: exit(0);
            default: {
                printf("wrong choice\n");
                break;
            }
        }
    }while(act!=4);
}