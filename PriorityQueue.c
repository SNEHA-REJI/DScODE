#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *p,*front,*rear,*ptr,*prev;
void Insert();
void Deletefront();
void Deletenode();
void Display();
void main()
{
    int choice,ch;
    front=NULL;
    do
    {
       printf("\nMENU\n");
       printf("1.Insertion\t2.Deletion\t3.Display\t4.Exit\n");
       printf("Enter choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               Insert();
               break;
           }
            case 2:
           {
           printf("Choose type of deletion\n");
           printf("1.Delete from front only\t2.Delete a specified node\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               Deletefront();
               break;
           }
           case 2:
           {
               Deletenode();
               break;
           }
           default:
           {
               printf("INVALID CHOICE\n");
               break;
           }
           }
           break;
           } 
           case 3:
           {
               Display();
               break;
           }
           case 4:
           {
                printf("Exiting Priority Queue program\n");
                break;
           }
           default:
           {
               printf("INVALID CHOICE");
               break;
           }
       }
    }
    while(choice!=4);
}
void Display()
{
    if(front==NULL)
    printf("Queue is Empty");
    else
    {
    ptr=front;
    printf("The Priority Queue is\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    }
}
void Insert()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    printf("Enter the priority of the node\n");
    scanf("%d",&p->priority);
    if(front==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        ptr=front;
        prev=NULL;
        while(ptr!=NULL && ptr->priority < p->priority)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(prev==NULL)
        {
            p->next=front;
            front=p;
        }
        else
        {
        prev->next=p;
        p->next=ptr;
        if(ptr==NULL)
        rear=p;
        }
    }
}
void Deletefront()
{
    if(front==NULL)
    printf("Queue is Empty");
    else if(front==rear)
    {
        ptr=front;
        front=NULL;
    	rear=NULL;
        free(ptr);
    }
    else
    {
	ptr=front;
	front=ptr->next;
	free(ptr);
    }
}
void Deletenode()
{
    int item;
    if(front==NULL)
    printf("Queue is Empty");
    else
    {
        printf("Enter data to be deleted\n");
        scanf("%d",&item);
        ptr=front;
        while(ptr->data!=item)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(front==rear)
        {
        ptr=front;
        front=NULL;
    	rear=NULL;
        free(ptr);
        }
        else if(ptr==front)
        {
	    ptr=front;
	    front=ptr->next;
	    free(ptr);
        } 
        else
        {
        prev->next=ptr->next;
        free(ptr);
        }
    }
}



