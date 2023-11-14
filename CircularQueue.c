#include <stdio.h>
int front=0,rear=0;
void Enqueue(int n,int item,int Q[50]);
void Dequeue(int Q[50],int n);
void Display(int Q[50],int n);
void main()
{
int ch,Q[50],n,item;
printf("Enter the size of queue\n");
scanf("%d",&n);
do{
printf("MENU\n");
printf("1.ENQUEUE\n");
printf("2.DEQUEUE\n");
printf("3.DISPLAY\n");
printf("4.IsEMPTY\n");
printf("5.IsFULL\n");
printf("6.EXIT\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
   
    case 1:
    {
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        Enqueue(n,item,Q);
        break;
    }
    case 2:
    {
        Dequeue(Q,n);
        break;
    }
    case 3:
    {
        Display(Q,n);
        break;
    }
    case 4:
    {
    if(front==rear)
    printf("Queue is Empty\n");
    else
    printf("Queue is not Empty\n");
    break;
    }
    case 5:
    {
    if((rear+1)%n==front)
    printf("Queue is Full\n");
    else
    printf("Queue is not Full\n");
    break;
    }
    case 6:
    {
        printf("Exiting Circular Queue Program\n");
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
void Enqueue(int n,int item,int Q[50])
{
    if((rear+1)%n==front)
    printf("Queue Full\n");
    else
    {
    rear=(rear+1)%n;
    Q[rear]=item;
    }
}
void Dequeue(int Q[50],int n)
{
    int item;
    if(front==rear)
    printf("Queue Empty\n");
    else
    {
        front=(front+1)%n;
        item=Q[front];
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




