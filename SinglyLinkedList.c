#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *p,*head,*tail,*ptr,*prev;
void insertatend(void);
void insertatbeginning(void);
void insertafternode(void);
void deletefrombeginning(void);
void deletefromend(void);
void deletenode(void);
void display(void);
void main()
{
    int choice;
    head=NULL;
    do
    {
       printf("\nMENU\n");
       printf("1.Insert at the end\t2.Insert at the beginning\t3.Insert after a node\t4.Delete from beginning\t5.Delete from end\t6.Delete a node\t7.Display List\t8.Exit\n");
       printf("Enter choice\n");
       scanf("%d",&choice);
       switch(choice)
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
               deletefrombeginning();
               break;
           }
            case 5:
           {
               deletefromend();
               break;
           }
            case 6:
           {
               deletenode();
               break;
           }
            case 7:
           {
               display();
               break;
           }
           case 8:
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
    while(choice!=8);
}
void insertatend(void)
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
}
void display(void)
{
    ptr=head;
    printf("The linked list is\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
void insertatbeginning(void)
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
}
void insertafternode(void)
{
    int node;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    ptr=head;
    printf("Enter the node after which new node is to be inserted\n");
    scanf("%d",&node);
    while(ptr->data!=node)
    {
      ptr=ptr->next; 
    }
    p->next=ptr->next;
    ptr->next=p;
}
void deletefrombeginning(void)
{
    if(head==NULL)
    printf("List is Empty");
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
    }
}
void deletefromend(void)
{
    if(head==NULL)
    printf("List is Empty");
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=NULL;
        tail=prev;
        free(ptr);
    }
}
void deletenode(void)
{
    int item;
    if(head==NULL)
    printf("List is Empty");
    else
    {
        printf("Enter data to be deleted\n");
        scanf("%d",&item);
        ptr=head;
        while(ptr->data!=item)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=ptr->next;
        free(ptr);
    }
}
