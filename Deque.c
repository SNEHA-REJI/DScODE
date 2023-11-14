#include <stdio.h>
int front=0,rear=0;
void InsertFront(int n,int item,int Q[50]);
void InsertRear(int n,int item,int Q[50]);
void DeleteRear(int Q[50],int n);
void DeleteFront(int Q[50],int n);
void Display(int Q[50],int n);
void main()
{
int ch,Q[50],n,item;
printf("Enter the size of queue\n");
scanf("%d",&n);
do{
printf("MENU\n");
printf("1.Insert at Front\t");
printf("2.Insert at Rear\t");
printf("3.Delete from Front\t");
printf("4.Delete from Rear\t");
printf("5.Display Queue\t");
printf("6.EXIT\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
   
    case 1:
    {
        printf("Enter the item to be inserted at front\n");
        scanf("%d",&item);
        InsertFront(n,item,Q);
        break;
    }
    case 2:
    {
        printf("Enter the item to be inserted at rear\n");
        scanf("%d",&item);
        InsertRear(n,item,Q);
        break;
    }
    case 3:
    {
        DeleteFront(Q,n);
        break;
    }
    case 4:
    {
        DeleteRear(Q,n);
        break;
    }
    case 5:
    {
        Display(Q,n);
        break;
    }
   
    case 6:
    {
        printf("Exiting Double Ended Queue Program\n");
        break;
    }
    default:
    {
    printf("Invalid Choice\n");
    break;
    }
}
}
while(ch!=6);
}
void InsertFront(int n,int item,int Q[50])
{
    if((rear+1)%n==front)
    printf("Queue is Full\n");
    else if(front==0)
    {
        Q[front]=item;
        front=n-1;
    }
    else
    {
    Q[front]=item;
    front=(front-1)%n;
    }
}
void InsertRear(int n,int item,int Q[50])
{
    if((rear+1)%n==front)
    printf("Queue is Full\n");
    else
    {
        rear=(rear+1)%n;
        Q[rear]=item;
    }
}
void DeleteFront(int Q[50],int n)
{
    int item;
    if(front==rear)
    printf("Queue is Empty\n");
    else
    {
        front=(front+1)%n;
        item=Q[front];
    }
}
void DeleteRear(int Q[50],int n)
{
    int item;
    if(front==rear)
    printf("Queue is Empty\n");
    else if(rear==0)
    {
        item=Q[rear];
        rear=n-1;
    }
    else
    {
        item=Q[rear];
        rear=(rear-1)%n;
    }
}
void Display(int Q[50],int n)
{
    int i;
    if(front==rear)
    printf("Queue Empty\n");
    else
    {
    i=(front+1)%n;
    printf("Displaying Queue:\n");
    while(i!=rear)
    {
    printf("%d\n",Q[i]);
    i=(i+1)%n;
    }
    printf("%d\n",Q[i]);
}
}






