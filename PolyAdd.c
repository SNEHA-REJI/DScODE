#include<stdio.h>
void InputPoly(int A[100],int t);
void Polyadd(int A[100],int B[100],int C[100]);
void DisplayPoly(int A[100],int t);
void Polyadd(int A[100],int B[100],int C[100])
{
int m,n,p=1,q=1,r=1;
m=A[0];
n=B[0];
while(p<=(2*m) && q<=(2*n))
{
if(A[p]==B[q])
{
C[r+1]=A[p+1]+B[q+1];
if(C[r+1]!=0)
{
C[r]=A[p];
r=r+2;
}
p=p+2;
q=q+2;
}
else if(A[p]<B[q])
{
C[r+1]=B[q+1];
C[r]=B[q];
q=q+2;
r=r+2;
}
else if(A[p]>B[q])
{
C[r+1]=A[p+1];
C[r]=A[p];
p=p+2;
r=r+2;
}
}
while(p<=(2*m))
{
C[r]=A[p];
C[r+1]=A[p+1];
p=p+2;
r=r+2;
}
while(q<=(2*n))
{
C[r]=B[q];
C[r+1]=B[q+1];
q=q+2;
r=r+2;
}
C[0]=r/2;
printf("Polynomial Addition Result using arrray\n");
DisplayPoly(C,(r-1));
}
void main()
{
int MA[100],MB[100],MC[100],term,term1,term2,ch;
printf("MENU\n");
printf("1.Input and Display Polynomial using array\n");
printf("2.Perform Polynomial addition of two polynomials and display\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
InputPoly(MA,term);
break;
}
case 2:
{
printf("Polynomial 1\n");
InputPoly(MA,term1);
printf("Polynomial 2\n");
InputPoly(MB,term2);
Polyadd(MA,MB,MC);
break;
}
}
}
void InputPoly(int A[100],int t)
{
int i;
printf("Enter number of terms in polynomial\n");
scanf("%d",&t);
printf("Enter exponent and then coefficient of each term in descending order of exponent for polynomial\n");
for(i=1;i<=(2*t);i++)
{
   scanf("%d",&A[i]);
}
A[0]=t;
printf("Polynomial Array\n");
DisplayPoly(A,2*t);
}
void DisplayPoly(int A[100],int t)
{
int i;
for(i=1;i<=t;i=i+2)
{
printf("%dx^%d",A[i+1],A[i]);
if(i<(t-2))
printf("+");
}
}


