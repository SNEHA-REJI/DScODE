#include <stdio.h>
int front=-1,rear=-1;
void Insert(int n,int item,int Q[50]);
void Dequeue(int Q[50]);
void Display(int Q[50]);
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
printf("4.EXIT\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
   
    case 1:
    {
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        Insert(n,item,Q);
        break;
    }
    case 2:
    {
        Dequeue(Q);
        break;
    }
    case 3:
    {
        Display(Q);
        break;
    }
    case 4:
    {
        printf("Exiting Stack Program\n");
        break;
    }
}
}
while(ch!=4);
}
void Insert(int n,int item,int Q[50])
{
    if(rear==n-1)
    printf("    Queue Full\n");
    else
    {
    rear=rear+1;
    Q[rear]=item;
    }
}
void Dequeue(int Q[50])
{
    int item;
    if(front==rear)
    printf("Queue Empty\n");
    else
    {
        front=front+1;
        item=Q[front];
    }
}
void Display(int Q[50])
{
    int i;
    if(front==rear)
    printf("Queue Empty\n");
    else
    {
    i=front+1;
    printf("Displaying queue:\n");
    while(i<=rear)
    {
    printf("%d\n",Q[i]);
    i=i+1;
    }
}
}

