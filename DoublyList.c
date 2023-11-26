#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *p,*head,*tail,*ptr,*prev;
void insertatend(void);
void insertatbeginning(void);
void insertafternode(void);
void insertbeforenode(void);
void deletefrombeginning(void);
void deletefromend(void);
void deletenode(void);
void displayforward(void);
void displaybackward(void);
void main()
{
    int choice,ch;
    head=NULL;
    do
    {
       printf("\nMENU\n");
       printf("1.Insertion\t2.Deletion\t3.Display List\t4.Exit\n");
       printf("Enter choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
           printf("Choose type of insertion\n");
           printf("1.Insert at the end\t2.Insert at the beginning\t3.Insert after a node\t4.Insert before a node\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               insertatend();
               break;
           }
           case 2:
           {
               insertatbeginning();
               break;
           }
            case 3:
           {
               insertafternode();            
               break;
           }
           case 4:
           {
               insertbeforenode();
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
           case 2:
           {
           printf("Choose type of deletion\n");
           printf("1.Delete from beginning\t2.Delete from end\t3.Delete a node\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               deletefrombeginning();
               break;
           }
           case 2:
           {
               deletefromend();
               break;
           }
            case 3:
           {
                deletenode();          
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
           printf("Choose type of Display\n");
           printf("1.Display Forward\t2.Display Backward\n");
           printf("Enter choice\n");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1:
           {
               displayforward();
               break;
           }
           case 2:
           {
               displaybackward();
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
           case 4:
           {
                printf("Exiting Linked List program");
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
void insertatend(void)
{  
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    if(head==NULL)
    {  
        head=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        p->next=NULL;    
    }
    tail=p;
}
void insertatbeginning(void)
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    if(head==NULL)
    {
        p->next=NULL;
        p->prev=NULL;
        tail=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
    }
    head=p;
}
void insertafternode(void)
{
    int node;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    ptr=head;
    printf("Enter the node after which new node is to be inserted\n");
    scanf("%d",&node);
    while(ptr->data!=node)
    {
      ptr=ptr->next;
    }
    p->next=ptr->next;
    ptr->next->prev=p;
    ptr->next=p;
    p->prev=ptr;
    if(ptr==NULL)
    printf("Item Not Found");
}
void insertbeforenode(void)
{
    int node;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    ptr=head;
    printf("Enter the node before which new node is to be inserted\n");
    scanf("%d",&node);
    while(ptr->data!=node)
    {
      ptr=ptr->next;
    }
    ptr->prev->next=p;
    p->prev=ptr->prev;
    ptr->prev=p;
    p->next=ptr;
    if(ptr==NULL)
    printf("Item Not Found");
}
void deletefrombeginning(void)
{
    if(head==NULL)
    printf("List is Empty");
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        tail=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free (ptr);
    }
}
void deletefromend(void)
{
   
    if(head==NULL)
    printf("List is Empty");
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        tail=NULL;
        free(ptr);
    }
    else
    {
        ptr=tail;
        tail=tail->prev;
        tail->next=NULL;
        free (ptr);
    }
}
void deletenode(void)
{
    int item;
    printf("Enter data to be deleted\n");
    scanf("%d",&item);
    if(head==NULL)
    printf("List is Empty");
    ptr=head;
    while(ptr->data!=item)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
}
  void displayforward(void)
{
    if(head==NULL)
    printf("List is Empty");
    else
    {
    ptr=head;
    printf("The linked list is\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    }
}
void displaybackward(void)
{
    if(head==NULL)
    printf("List is Empty");
    else
    {
    ptr=tail;
    printf("The linked list is\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->prev;
    }
    }
}
