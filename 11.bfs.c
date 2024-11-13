#include<stdio.h>
#include<stdlib.h>
int queue[20],vis[20];
int front=-1,rear=-1;

void enqueue(int data){
    if(rear==19){
        printf("queue full \n");
    }else{
        if(rear==-1){
            front++;
            rear++;
            queue[rear]=data;
            return;
        }
        rear++;
        queue[rear]=data;
        
    }
}

int dequeue(){
    int item;
    if(front==-1){
        printf("queue empty");
        return 0;
    }
    item=queue[front];
    front++;
    return item;
}

void bfs(int m[20][20],int n){
    int s,p,i   ;
    printf("enter a source vertex:");
    scanf("%d",&s);
    enqueue(s);

    vis[s]=1;
    p = dequeue();
    if(p!=0) printf("%d->",p);

    while(p!=0){
        for(i=1;i<=n;i++){
            if(m[p][i] !=0 && vis[i]==0){
                enqueue(i);
                vis[i]=1;
            }
        }
        p=dequeue();
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

    bfs(matrix,n);
}

// ABC
//A101 
//B001 
//C010 