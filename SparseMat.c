#include <stdio.h>
void AddSparse(int A[50][50],int B[50][50]);
void Transpose(int A[50][50]);
void main()
{
    int ch,m,n,A[50][50],B[50][50],i,j;
    printf("MENU\n");
    printf("1.Sparse Matrix Addition\n");
    printf("2.Sparse Matrix Transpose\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
           
            printf("Enter the no. of non zero elements in sparse matrix A\n ");
            scanf("%d",&m);
            printf("Enter the triplet representation of sparse matrix A\n");
            for(i=0;i<=m;i++)
            {
                for(j=1;j<=3;j++)
                {
                    scanf("%d",&A[i][j]);
                }
            }
            printf("Enter the no. of non zero elements in sparse matrix B\n ");
            scanf("%d",&n);
               printf("Enter the triplet representation of sparse matrix B\n");
            for(i=0;i<=n;i++)
            {
                for(j=1;j<=3;j++)
                {
                    scanf("%d",&B[i][j]);
                }
            }
            if(A[0][1]!=B[0][1] || A[0][2]!=B[0][2])
            printf("Matrix Addition Not Possible\n");
            else
            AddSparse(A,B);
            break;
        }
        case 2:
        {
       
            printf("Enter the no. of non zero elements in sparse matrix A\n ");
            scanf("%d",&m);
            printf("Enter the triplet representation of sparse matrix A\n");
            for(i=0;i<=m;i++)
            {
                for(j=1;j<=3;j++)
                {
                    scanf("%d",&A[i][j]);
                }
            }
            Transpose(A);
            break;
        }
    }
}
void AddSparse(int A[50][50],int B[50][50])
{
    int C[50][50],p,q,m,n,r,i,j;
    m=A[0][3];
    n=B[0][3];
    p=1;
    q=1;
    r=1;
   while(p<=m && q<=n)
   {
    if(A[p][1]<B[q][1])
    {
        C[r][1]=A[p][1];
        C[r][2]=A[p][2];
        C[r][3]=A[p][3];
        p=p+1;
        r=r+1;
    }
    else if(A[p][1]>B[q][1])
    {
        C[r][1]=B[q][1];
        C[r][2]=B[q][2];
        C[r][3]=B[q][3];
        q=q+1;
        r=r+1;
    }
    else
    {
        if(A[p][2]<B[q][2])
        {
            C[r][1]=A[p][1];
            C[r][2]=A[p][2];
            C[r][3]=A[p][3];
            p=p+1;
            r=r+1;
        }
        else if(A[p][2]>B[q][2])
        {
            C[r][1]=B[q][1];
            C[r][2]=B[q][2];
            C[r][3]=B[q][3];
            q=q+1;
            r=r+1;
           
        }
   
         else
        {
        C[r][1]=A[p][1];
        C[r][2]=A[p][2];
        C[r][3]=A[p][3]+B[q][3];
        p=p+1;
        q=q+1;
        r=r+1;
        }
    }
   }
    C[0][1]=A[0][1];
    C[0][2]=A[0][2];
    C[0][3]=r-1;
    printf("Addition Result:\n");
    for(i=0;i<r;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}

void Transpose(int A[50][50])
{
    int C[50][50],col,m,n,t,i,j,p,q;
m=A[0][1];
n=A[0][2];
t=A[0][3];
C[0][1]=n;
C[0][2]=m;
C[0][3]=t;
if(t<=0)
return;
q=1;
for(col=0;col<=n-1;col++){
for(p=1;p<=t;p++)
{
if (A[p][2]==col)
{
    C[q][1]=A[p][2];
    C[q][2]=A[p][1];
    C[q][3]=A[p][3];
    q=q+1;
}
}
}
printf("Transpose Result:\n");
    for(i=0;i<=t;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}


