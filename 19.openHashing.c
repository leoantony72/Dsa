//search function is not implemented!!
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node{
    int data;
    struct node* next;
};
struct node* hashTable[MAX];

struct node* createNode(int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

int hashFucntion(int key){
    return key%MAX;
}

void insert(){
    int data,idx;
    printf("enter data to insert:");
    scanf("%d",&data);
    struct node* p = createNode(data); 

    idx = hashFucntion(data);
    if(hashTable[idx]==NULL){
        hashTable[idx]=p;
    }else{
        p->next = hashTable[idx];
        hashTable[idx] = p;
    }
}

void delete(){
    int data;
    printf("enter data to delete:");
    scanf("%d",&data);
    int idx = hashFucntion(data);
    struct node* temp = hashTable[idx]; 
    struct node* prev = NULL;


    if(hashTable[idx]->next == NULL){
        hashTable[idx]==NULL;
    }else{
        while(temp!=NULL){
            if(temp->data==data){
                if(prev==NULL){
                    hashTable[idx]=temp->next;
                }else{
                    prev->next = temp->next;
                }
                free(temp);
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
}

void display(){
    int i;
    for(i=0;i<MAX;i++){
        struct node* temp = hashTable[i];
        printf("index %d:",i);
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");

    }
}

int main(){
    for(int i=0; i<MAX;i++){
        hashTable[i]=NULL;
    }

    int act;
    do{
        printf("1.insert\t2.delete\t3.display\t4.Exit\n");
        scanf("%d",&act);
        switch(act){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display();break;
            case 4: exit(0);
            default: {
                printf("wrong choice\n");
                break;
            }
        }
    }while(act!=4);
}