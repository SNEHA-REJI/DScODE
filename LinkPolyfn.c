#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *p,*top,*front,*rear,*temp;
void Push();
void Pop();
void DisplayS();
void EnqueueQ();
void DequeueQ();
void DisplayQ();
void EnqueueCQ();
void DequeueCQ();
void DisplayCQ();
void main()
{
    int choice=-1,ch=-1;
    do
    {
       printf("\nMENU\n");
       printf("1.Stack\t2.Linear Queue\t3.Circular Queue\t4.Exit\n");
       printf("Enter choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
            top=NULL;
            ch=-1;
            do{
           printf("\nChoose the operation to be performed in the stack\n");
           printf("1.Push\t2.Pop\t3.Display\t4.Exit\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               Push();
               break;
           }
           case 2:
           {
               Pop();
               break;
           }
            case 3:
           {
               DisplayS();            
               break;
           }
           case 4:
           {
               printf("\nExiting Stcak Operation\n");
               break;
           }
           default:
           {
               printf("\nINVALID CHOICE\n");
               break;
           }
           }
           }
           while(ch!=4);
           break;
           }
           case 2:
           {
            front=NULL;
            rear=NULL;
            ch=-1;
            do{
           printf("\nChoose the operation to be performed in the linear queue\n");
           printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               EnqueueQ();
               break;
           }
           case 2:
           {
               DequeueQ();
               break;
           }
           case 3:
           {
                DisplayQ();
                break;
           }
           case 4:
           {
               printf("\nExiting Queue Operation\n");
               break;
           }
           default:
           {
               printf("\nINVALID CHOICE\n");
               break;
           }
           }
           }
           while(ch!=4);
           break;
           }
           
           
           case 3:
           {
            front=NULL;
            rear=NULL;
            ch=-1;
            do{
           printf("\nChoose the operation to be performed in the circular queue\n");
           printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               EnqueueCQ();
               break;
           }
           case 2:
           {
               DequeueCQ();
               break;
           }
           case 3:
           {
                DisplayCQ();
                break;
           }
           case 4:
           {
               printf("\nExiting Circular Queue Operation\n");
               break;
           }
           default:
           {
               printf("\nINVALID CHOICE\n");
               break;
           }
           }
           }
           while(ch!=4);
           break;
           }
           case 4:
           {
                printf("\nExiting Linked List program");
                break;
           }
           default:
           {
               printf("\nINVALID CHOICE");
               break;
           }
       }
    }
    while(choice!=4);
}
void Push()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    if(top==NULL)
    p->next=NULL;
    else
    p->next=top;
    top=p;
}
void Pop()
{
    if(top==NULL)
    printf("Stack is Empty");
    else
    {
        top=top->next;
        free (p);
    }
}
void DisplayS()
{
    if(top==NULL)
    printf("Stack is Empty\n");
    else
    {
    temp=top;
    printf("The stack is:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
}
void EnqueueQ()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
void DequeueQ()
{
    if(front==NULL)
    printf("Queue is Empty");
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        temp=front;
        front=temp->next;
        free(temp);
    }
}
void DisplayQ()
{
    if(front==NULL && rear==NULL)
    printf("Queue is Empty");
    else
    {
        temp=front;
        printf("The Linear Queue is:\n");
        while(temp!=NULL)
        {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
    }
}
void EnqueueCQ()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    if(front==NULL && rear==NULL)
    {
        front=p;
        rear=p;
        rear->next=p;
    }
    else
    {
        rear->next=p;
        rear=p;
        p->next=front;
    }
}
void DequeueCQ()
{
    if(front==NULL && rear==NULL)
    printf("Queue is Empty");
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
        free(p);
    }
    else
    {
        temp=front;
        front=temp->next;
        free(temp);
        rear->next=front;
    }
}
void DisplayCQ()
{
    if(front==NULL && rear==NULL)
    printf("Queue is Empty");
    else
    {
        temp=front;
        printf("The Circular Queue is:\n");
        while(temp!=rear->next)
        {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
    }
}

