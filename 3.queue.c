#include<stdio.h>
#include<stdlib.h>
#define Size 5
int queue[Size];
int front=-1, rear=-1;

void enqueue(){
    int data;
    if(rear==Size-1){
        printf("queue is full\n");
        return;
    }else if(front==-1){
        front=rear=0;
        printf("enter element to insert: ");
        scanf("%d",&data);
        queue[rear]=data;
    }else{
        rear++;
        printf("enter element to insert: ");
        scanf("%d",&data);
        queue[rear]=data;
    }
}

void dequeue(){
    int item;
    if((front==-1 && rear==-1) || (front > rear) ){
        printf("queue is empty\n");
        return;
    }else{
        item = queue[front];
        front++;
        printf("%d Deleted\n",item);
    }
}

void display(){
    int i;
    if((front==-1) && (front>rear)){
        printf("no elements in queue\n");
        return;
    }
    printf("---output---\n");
    for(i=front;i<Size;i++){
        printf("%d\n",queue[i]);
    }
}

void main(){
    int act;
    do{
        printf("1.enqueue\t2.dequeue\t3.display\t4.Exit\n");
        scanf("%d",&act);
        switch(act){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display();break;
            case 4: exit(0);
            default: {
                printf("wrong choice\n");
                break;
            }
        }
    }while(act!=4);
}