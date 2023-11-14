#include<stdio.h>
void LinearS(int A[50],int n,int sk);
void BinaryS(int A[50],int n,int sk);
void main()
{
    int choice,i,j,n,A[50],sk,temp;
       printf("Enter the number of terms in the array\n");
       scanf("%d",&n);
       printf("Enter the elements in the array\n");
       for(i=0;i<n;i++)
       {
          scanf("%d",&A[i]);
       }
       printf("Enter the element to be searched\n");
       scanf("%d",&sk);
       printf("\nMENU\n");
       printf("1.Linear Search\t2.Binary Search\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               LinearS(A,n,sk);
               break;
           }
            case 2:
           {
               printf("Array should be sorted to implement binary search \n**Implementing Bubble Sort**\n");
               for(i=0;i<n;i++)
               {
                   for(j=0;j<n-1;j++)
                   {
                       if(A[j]>A[j+1])
                       {
                           temp=A[j];
                           A[j]=A[j+1];
                           A[j+1]=temp;
                       }
                   }
               }
               printf("Sorted Array:");
               for(i=0;i<n;i++)
               {
                   printf("%d\t",A[i]);
               }
               BinaryS(A,n,sk);
               break;
           }
           default:
           {
               printf("INVALID CHOICE\n");
               break;
           }
       }
}
void LinearS(int A[50],int n,int sk)
{
    int i,found=0;
    for(i=0;i<n;i++)
    {
        if(A[i]==sk)
        {
            found=1;
            printf("Element %d is at position %d\n",sk,(i+1));
        }
    }
    if(found==0)
    printf("Element not found\n");
}
void BinaryS(int A[50],int n,int sk)
{
    int l=0,u=n-1,m,found=0;
    while(l<=u)
    {
        m=(l+u)/2;
        if(sk>A[m])
        l=m+1;
        else if(sk<A[m])
        u=m-1;
        else if(sk==A[m])
        {
            found=1;
            printf("\nElement %d is at position %d in the sorted array\n",sk,(m+1));
            break;
        }
    }
    if(found==0)
    printf("\nElement not found\n");
}
