#include<stdio.h>
void fifo(int pages[100],int n,int capacity)
{
    int frames[capacity];
    int front=0,faults=0;
    for (int i=0;i<capacity;i++)
    {
        frames[i]=-1;
    }
    printf("\npages\tframes\n");
    for(int i=0;i<n;i++)
    {
        int found=0;
        for(int j=0;j<capacity;j++)
        {
            if (frames[j]==pages[i])
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            frames[front]=pages[i];
            front=(front+1)%capacity;
            faults++;
        }
        printf("%d",pages[i]);
        for(int j=0;j<capacity;j++)
        {
            if(frames[j]!=-1)
            {
                printf("%d",frames[j]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("total number of page fault is %d",faults);
}

int main()
{
    int n,capacity;
    int pages[100];
    printf("enter the number of pages");
    scanf("%d",&n);
    printf("Enter the number of page sequence:");
    for (int i=0;i<n;i++)
    {
        printf("page %d:",i+1);
        scanf("%d",&pages[i]);
    }
    printf("Enter the frames:");
    scanf("%d",&capacity);
    fifo(pages,n,capacity);
    return(0);

}