
#include <stdio.h>
#include <string.h>
#include <math.h>
int stack[50];
char exp_n[50],post_fix[50];
int top=-1,result;
void POSTFIX();
int precedence(char x);
void Push(char x);
int Evaluate();
int Pop();
void main()
{
int ch;
printf("Name:Kesiya Mariam Reji\nBranch:CS-B\nRoll No.:54\n");
printf("MENU\n");
printf("1.Convert Infix to Postfix\n");
printf("2.Evaluate Postfix Expression\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
   
    case 1:
    {
        printf("Enter the infix expression\n");
        scanf("%s",&exp_n);
        POSTFIX();
        break;
    }
    case 2:
    {
        printf("Enter the postfix expression\n");
        scanf("%s",&post_fix);
        result=Evaluate();
        printf("The evaluation result of postfix expression\n");
        printf("%d\n",result);
        break;
    }
    default:
    {
        printf("INVALID CHOICE\n");
        break;
    }
}
}
void Push(char x)
{
    top=top+1;
    stack[top]=x;
   
}
int Pop()
{
    int item;
    if(top==-1)
    printf("Stack is Empty\n");
    else
    {
        item=stack[top];
        top=top-1;
        return item;
    }
}
void POSTFIX()
{
    int i,j=0;
    char x,next;
    for(i=0;i<strlen(exp_n);i++)
    {
        x=exp_n[i];
        switch(x)
        {
             case '(':
            {
             Push(x);
             break;
            }
             case ')':
            {
             while((next=Pop())!='(')
             {
             post_fix[j++]=next;
             }
             break;
            }
             case '+':
             case '-':
             case '*':
             case '/':
             case '%':
             while(!(top==-1) && precedence(stack[top])>=precedence(x))
             {
                 post_fix[j++]=Pop();
             }
             Push(x);
             break;
             case '^':
             while(!(top==-1) && precedence(stack[top])>precedence(x))
             {
                 post_fix[j++]=Pop();
             }
             Push(x);
             break;
             default:
            {
                post_fix[j++]=x;
                break;
            }
           
        }
    }
    while(top>=0)
    {
        post_fix[j++]=Pop();
    }
    post_fix[j]='$';
    printf("The equivalent postfix expression:\n");
    printf("%s\n",post_fix);
}
int precedence(char x)
{
    switch(x)
    {
        case'^':
        return 3;
        case '/':
        case '*':
        case '%':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
int Evaluate()
{
    int i,z1,z2,z;
    top=-1;
    for(i=0;i<strlen(post_fix);i++)
    {
    if(post_fix[i]>='0' && post_fix[i]<='9') // comparison of ASCII codes
    {
        Push(post_fix[i]-'0');
    }
    else
    {
       z1=Pop();
       z2=Pop();
       switch(post_fix[i])
       {
           case '+':
           {
            z=z2+z1;
            Push(z);
            break;
           }
           case '-':
           {
            z=z2-z1;
            Push(z);
            break;
           }
           case '*':
           {
            z=z2*z1;
            Push(z);
            break;
           }
           case '/':
           {
            z=z2/z1;
            Push(z);
            break;
           }
           case '^':
           {
            z=pow(z2,z1);
            Push(z);
            break;
           }
           case '%':
           {
            z=z2%z1;
            Push(z);
            break;
           }
       }
       
    } }
    return stack[0];
}




