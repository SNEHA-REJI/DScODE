#include <stdio.h>
#include <stdlib.h>

struct block
{
    int bno,bsize,pno,frspace;
    struct block *prev,*next;
} *head,*tail,*ptr,*pt;

struct processes
{
    int pid,psize,status;
}p[10];

int nb,np;

void display()
{
    int i=0;
    printf("\nBlock Details\n");
    printf("Blockno    Block-size     Allocated-process   FreeSpace\n");
    for (ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d           %d              %d                 %d\n",ptr->bno,ptr->bsize,ptr->pno,ptr->frspace);
    }
    printf("\nProcess Details\n");
    printf("Process  Process-size    Allocated-block\n");
    for(i=0;i<np;i++)
    {
    printf("%d          %d              %d\n",p[i].pid,p[i].psize,p[i].status);
    }
}

void firstfit()
{
    for(int i=0;i<np;i++)
    {
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            if (ptr->pno==-1 && ptr->bsize>=p[i].psize)
            {
                p[i].status=ptr->bno;
                ptr->pno=p[i].pid;
                ptr->frspace-=p[i].psize;
                break;
            }
        }
    }
}

void bestfit()
{
	struct block *smallest;
	int smsize;
	for(int i=0;i<np;i++)
	{
		smallest=NULL;
		smsize=100000;
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
		{
			if (ptr->pno==-1 && ptr->bsize>=p[i].psize && ptr->bsize<=smsize)
			{
				smallest=ptr;
				smsize=ptr->bsize;
			}
		}
		if(smallest!=NULL)
		{
			smallest->frspace-=p[i].psize;
			smallest->pno=p[i].pid;
			p[i].status=smallest->bno;
		}
	}
}

void worstfit()
{
	struct block *largest;
	int large=0;
	for(int i=0;i<np;i++)
	{
		large=0;
		largest=NULL;
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
		{
			if (ptr->pno==-1 && ptr->bsize>=p[i].psize && ptr->bsize>=large)
			{
				largest=ptr;
				large=ptr->bsize;
			}
		}
		if(largest!=NULL)
		{
			largest->pno=p[i].pid;
			largest->frspace-=p[i].psize;
			p[i].status=largest->bno;
		}
	}
}

void clear()
{
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        ptr->frspace=ptr->bsize;
        ptr->pno=-1;
    }
    for(int i=0;i<np;i++)
        p[i].status=-1;
}

void main()
{
    int ch=0;
    printf("enter the number of blocks : ");
    scanf("%d",&nb);
    printf("enter the number of processes : ");
    scanf("%d",&np);
    printf("enter block details\n");
    for(int i=0;i<nb;i++)
    {
        pt=(struct block*)malloc(sizeof(struct block));
        pt->prev=pt->next=NULL;
        if (head==NULL && tail==NULL)
        {
            head=tail=pt;
        }
        else
        {
            tail->next=pt;
            pt->prev=tail;
            tail=pt;
        }
        printf("Enter block %d size  : ",i+1);
        scanf("%d",&pt->bsize);
        pt->frspace=pt->bsize;
        pt->bno=i+1;
        pt->pno=-1;
    }
    printf("enter process details\n");
    for(int i=0;i<np;i++)
    {
        p[i].pid=i+1;
        printf("Process size of P[%d] : ",i+1);
        scanf("%d",&p[i].psize);
        p[i].status=-1;
    }
    while(1)
    {
        printf("MENU  1:FIRST-FIT  2:BEST-FIT  3:WORST-FIT  4:EXIT : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                firstfit();
                display();
                clear();
                break;
            }
            case 2:
            {
            	bestfit();
            	display();
            	clear();
            	break;
            }
            case 3:
            {
            	worstfit();
            	display();
            	clear();
            	break;
            }
            case 4:
                exit(0);
        }
    }
}
