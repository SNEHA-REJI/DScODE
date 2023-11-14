#include <stdio.h>
int top=-1;
void Push(int n,int item,int stack[50]);
void Pop(int stack[50]);
void Peek(int stack[50]);
void Display(int stack[50]);
void main()
{
int ch,stack[50],n,item;
printf("Enter the size of stack\n");
scanf("%d",&n);
do{
printf("MENU\n");
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.PEEP\n");
printf("4.DISPLAY\n");
printf("5.EXIT\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
   
    case 1:
    {
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        Push(n,item,stack);
        break;
    }
    case 2:
    {
        Pop(stack);
        break;
    }
    case 3:
    {
    Peek(stack);
    break;
    }
    case 4:
    {
        Display(stack);
        break;
    }
    case 5:
    {
        printf("Exiting Stack Program\n");
        break;
    }
    default:
    {
    printf("Invalid Choice\n");
    break;
    }
}
}
while(ch!=5);
}
void Push(int n,int item,int stack[50])
{
    if(top==n-1)
    printf("Stack Full\n");
    else
    {
    top=top+1;
    stack[top]=item;
    }
}
void Pop(int stack[50])
{
    int item;
    if(top==-1)
    printf("Stack Empty\n");
    else
    {
        item=stack[top];
        top=top-1;
    }
}
void Peek(int stack[50])
{
if(top!=-1)
printf("%d\n",stack[top]);
}
void Display(int stack[50])
{
    int i;
    if(top==-1)
    printf("Stack Empty\n");
    else
    {
    i=top;
    printf("Displaying stack:\n");
    while(i>=0)
    {
    printf("%d\n",stack[i]);
    i=i-1;
    }
}
}



