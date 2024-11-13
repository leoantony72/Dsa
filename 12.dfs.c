#include<stdio.h>
#include<stdlib.h>
int queue[20],vis[20];
int stack[20],top=-1;
int front=-1,rear=-1;

void push(int data){
    if(top==-1){
        top++;
        stack[top]=data;
        return;
    }
    top++;
    stack[top]=data;
}

int pop(){
    int item;
    if(top==-1){
        return 0;
    }
    item = stack[top];
    top--;
    return item;
}

void dfs(int m[20][20],int n){
    int s,p,i   ;
    printf("enter a source vertex:");
    scanf("%d",&s);
    push(s);

    vis[s]=1;
    p = pop();
    if(p!=0) printf("%d->",p);

    while(p!=0){
        for(i=1;i<=n;i++){
            if(m[p][i] !=0 && vis[i]==0){
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0){
            printf("%d->",p);
        }
    }
}

void main(){

    int n,i,j;
    int matrix[20][20];
    printf("enter the no.of vertices:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }

    dfs(matrix,n);
}

// ABC
//A101 
//B001 
//C010 