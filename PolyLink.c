#include<stdio.h>
#include<stdlib.h>
struct node
{
 int coeff;
 int expo;
 struct node *next;
};
struct node *p,*q,*r,*m,*head1,*head2,*head3,*tail1,*tail2,*tail3,*head4,*tail4,*ptr,*pre;
void main()
{
head1=NULL;
head2=NULL;
head3=NULL;
head4=NULL;
int i=0,j=0,t1,t2,ch;
do{
printf("\nMENU\n");
printf("1.Enter Polynomial 1 & Display\n");
printf("2.Enter Polynomial 2 & Display\n");
printf("3.Perform Polynomial Addition\n");
printf("4.Perform Polynomial Multiplication\n");
printf("5.EXIT\n");
printf("Enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("\nEnter the no. of terms of polynomial 1\n");
scanf("%d",&t1);
printf("Enter Polynomial 1\n");
while(i<t1)
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the coefficient\n");
scanf("%d",&p->coeff);
printf("Enter the exponent\n");
scanf("%d",&p->expo);
p->next=NULL;
if(head1==NULL)
{
head1=p;
tail1=p;
}
else
{
tail1->next=p;
tail1=p;
}
 i++;
}
p=head1;
printf("Polynomial 1:\n");
while(p!=NULL)
{
printf("%dx^%d",p->coeff,p->expo);
if(p->next!=NULL)
printf("+");
p=p->next;
}
break;
}
case 2:
{
printf("\nEnter the no. of terms of polynomial 2\n");
scanf("%d",&t2);
printf("Enter Polynomial 2\n");
while(j<t2)
{
q=(struct node*)malloc(sizeof(struct node));
printf("Enter the coefficient\n");
scanf("%d",&q->coeff);
printf("Enter the exponent\n");
scanf("%d",&q->expo);
q->next=NULL;
if(head2==NULL)
{
head2=q;
tail2=q;
}
else
{
tail2->next=q;
tail2=q;
}
j++;
}
q=head2;
printf("Polynomial 2:\n");
while(q!=NULL)
{
printf("%dx^%d",q->coeff,q->expo);
if(q->next!=NULL)
printf("+");
q=q->next;
}
break;
}
case 3:
{
p=head1; q=head2;
while(p!=NULL && q!=NULL)
{
r=(struct node*)malloc(sizeof(struct node));
if(head3==NULL)
{
head3=r;
tail3=r;
}
else
{
tail3->next=r;
tail3=r;
}
if(p->expo>q->expo)
{
r->expo=p->expo;
r->coeff=p->coeff;
p=p->next;
}
else if(p->expo<q->expo)
{
r->expo=q->expo;
r->coeff=q->coeff;
q=q->next;
}
else
{
if((p->coeff+q->coeff)!=0)
{
r->expo=p->expo;
r->coeff=p->coeff+q->coeff;
}
p=p->next;
q=q->next;
}
}
while(p!=NULL)
{
r=(struct node*)malloc(sizeof(struct node));
if(head3==NULL)
{
head3=r;
tail3=r;
}
else
{
tail3->next=r;
tail3=r;
}
r->expo=p->expo;
r->coeff=p->coeff;
p=p->next;
}
while(q!=NULL)
{
r=(struct node*)malloc(sizeof(struct node));
if(head3==NULL)
{
head3=r;
tail3=r;
}
else
{
tail3->next=r;
tail3=r;
}
r->expo=q->expo;
r->coeff=q->coeff;
q=q->next;
}
r=head3;
while(r!=NULL)
{
ptr=r->next;
while(ptr!=NULL)
{
if(r->expo==ptr->expo)
{
r->coeff=r->coeff+ptr->coeff;
ptr->coeff=0;
}
ptr=ptr->next;
}
r=r->next;
}
r=head3; ptr=head3;
printf("\nThe resultant polynomial:\n");
while(r!=NULL)
{
if(r->coeff!=0)
{
printf("%dx^%d",r->coeff,r->expo);
if(r->next!=NULL)
printf("+");
}
r=r->next;
}
head3=NULL;
break;
}
case 4:
{
p=head1;
while(p!=NULL)
{
q=head2;
while(q!=NULL)
{
m=(struct node*)malloc(sizeof(struct node));
if(head4==NULL)
{
head4=m;
tail4=m;
}
else
{
tail4->next=m;
tail4=m;
}
m->coeff=p->coeff*q->coeff;
m->expo=p->expo+q->expo;
q=q->next;
}
p=p->next;
}
m=head4;
while(m!=NULL)
{
pre=m->next;
while(pre!=NULL)
{
if(m->expo==pre->expo)
{
m->coeff=m->coeff+pre->coeff;
pre->coeff=0;
}
pre=pre->next;
}
m=m->next;
}
m=head4; pre=head4;
printf("\nThe resultant polynomial:\n");
while(m!=NULL)
{
if(m->coeff!=0)
{
printf("%dx^%d",m->coeff,m->expo);
if(m->next!=NULL)
printf("+");
}
m=m->next;
}
head4=NULL;
break;
}
case 5:
{
printf("Exiting Program\n");
break;
}
default:
{
printf("INVALID CHOICE");
break;
}
}
}
while(ch!=5);
}




