
#include<stdio.h>
void InputPoly(int A[100],int t);
void PolyMultiply(int A[100],int B[100],int C[100],int D[100]);
void DisplayPoly(int A[100],int t);
void PolyMultiply(int A[100],int B[100],int C[100],int D[100]) 
{
int m,n,q=1,p=1,r=1,i,s,t;
m=A[0];
n=B[0];
while(p<=(2*m))
{
    q=1;
    while(q<=(2*n))
    {
      C[r]=A[p]+B[q];
      C[r+1]=A[p+1]*B[q+1];
      q=q+2;
      r=r+2;
    }
    p=p+2;
}
t=r/2;
r=1;
while(r<=(2*t))
{
  i=r+2;
  while(i<=(2*t))
  {
     if(C[r]==C[i]) 
     {
         C[r+1]=C[r+1]+C[i+1];
         C[i+1]=0;
     }
     i=i+2;
  }
  r=r+2;
}
r=1,s=1;
while(r<=(2*t))
{
   if(C[r+1]!=0) 
   {
       D[s]=C[r];
       D[s+1]=C[r+1];
       s=s+2;
   }
   r=r+2;
}
printf("\nPolynomial Multiplication Result using arrray\n");
DisplayPoly(D,(s-1));
}
void main()
{
int MA[100],MB[100],MC[100],MD[100],term1,term2;
printf("\nPolynomial 1\n");
InputPoly(MA,term1);
printf("\nPolynomial 2\n");
InputPoly(MB,term2);
PolyMultiply(MA,MB,MC,MD);
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
printf("(%dx^%d)",A[i+1],A[i]);
if(i<(t-2))
printf("+");
}
}


