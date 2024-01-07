
#include <stdio.h>
void quicksort(int A[],int left,int right);
void displayArray(int A[], int N);
void main()
{
int arr[100],n;
printf("Enter the size of Array\n");
scanf("%d",&n);
printf("Enter the elements of the Array\n");
for(int i=0;i<n;i++)
{
  scanf("%d",&arr[i]);
}
printf("Given array: \t");
displayArray(arr,n);
quicksort(arr,0,n-1);
printf("After Quick Sort\n");
printf("\nSorted Array: \t");
displayArray(arr,n);
}
void quicksort(int A[],int left,int right)
{
int i,j,pivot,temp;
if(left<right)
{
pivot=left;
i=left;
j=right;
while(i<j)
{
while(A[i]<A[pivot])
{
i=i+1;
}
while(A[j]>A[pivot])
{
j=j-1;
}
if(i<j)
{
temp=A[i];
A[i]=A[j];
A[j]=temp;
}
}
temp=A[pivot];
A[pivot]=A[j];
A[j]=temp;
quicksort(A,left,j-1);
quicksort(A,j+1,right);
}
}
void displayArray(int A[],int N)
{
int i;
for(i = 0;i<N;i++)
printf("%d ",A[i]);
printf("\n");
}



