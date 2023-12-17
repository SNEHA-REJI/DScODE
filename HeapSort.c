
#include <stdio.h>
void heapsort(int A[100],int N);
void heapify(int A[100],int N,int i);
void swap(int A[100],int i,int j);
void displayArray(int A[100], int N);
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
heapsort(arr,n);
printf("After Heap Sort\n");
printf("\nSorted Array: \t");
displayArray(arr,n);
}
void heapsort(int A[100],int N)
{
int i;
i=(N/2)-1;
while(i>=0)
{
heapify(A,N,i);
i=i-1;
}
i=N-1;
while(i>0)
{
swap(A,0,i);
heapify(A,i,0);
i=i-1;
}
}
void heapify(int A[100],int N,int i)
{
int largest=i;
int left=(2*i)+1;
int right=(2*i)+2;
if((A[left]>A[largest]) && (left<N))
largest=left;
if ((A[right]>A[largest]) && (right<N))
largest=right;
if(largest!=i)
{
  swap(A,i,largest);
  heapify(A,N,largest);
}
}
void swap(int A[100],int i,int j)
{
int temp;
temp=A[i];
A[i]=A[j];
A[j]=temp;
}
void displayArray(int A[100],int N)
{
int i;
for(i = 0;i<N;i++)
printf("%d ",A[i]);
printf("\n");
}


