//stack using array
#include<stdio.h>
#include<stdlib.h>
#define Size 5
int stack[Size];
int top = -1;

void push(){
    int data;
    if(top-1 == Size){
        printf("stack overflow\n");
        return;
    }
    printf("enter data: ");
    scanf("%d",&data);

    top++;
    stack[top]=data;
}

void pop(){
    int data;
    if(top==-1){
        printf("stack underflow\n");
        return;
    }
    data = stack[top];
    top--;
}

void display(){
    int i;
    if(top==-1){
        printf("no elements in stack\n");
        return;
    }
    printf("---output---\n");
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}


void main(){
    int act;
    do{
        printf("1.push\t2.pop\t3.display\t4.Exit\n");
        scanf("%d",&act);
        switch(act){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display();break;
            case 4: exit(0);
            default: {
                printf("wrong choice\n");
                break;
            }
        }
    }while(act!=4);
}