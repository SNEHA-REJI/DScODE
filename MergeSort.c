
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void displayArray(int A[], int size);
void main()
{
int choice;
do
{
int arr[10],n;
printf("\nMENU\n");
printf("1.Inserting Array\t2.Perform Merge Sort\t3.Display Sorted Array\t4.Exit\n");
scanf("%d",&choice);
switch(choice)
{
  case 1:
  {
printf("Enter the size of Array\n");
scanf("%d",&n);
printf("Enter the elements of the Array\n");
for(int i=0;i<n;i++)
{
   scanf("%d",&arr[i]);
}
        printf("Given array is \n");
        displayArray(arr,n);
        break;
   }
   case 2:
   {
        mergeSort(arr,0,n-1);
        break;
   }
   case 3:
   {
  printf("\nSorted array is \n");
displayArray(arr,n);
break;
   }
   case 4:
   {
    printf("Exiting.......\n");
    break;
   }
   default:
   {
    printf("INVALID CHOICE\n");
    break;
   }
}
}
while(choice!=4);
}
void merge(int arr[],int l,int m,int r)
{
int i,j,k;
int n1=m-l+1;
int n2=r-m;
int L[n1],R[n2];
for(i = 0;i<n1;i++)
L[i]=arr[l+i];
for(j=0;j<n2;j++)
R[j]=arr[m+1+j];
i=0;
j=0;
k=l;
while(i<n1&&j<n2)
{
if(L[i]<=R[j])
{
arr[k]=L[i];
i++;
}
else
{
arr[k]=R[j];
j++;
}
k++;
}
while(i<n1)
{
arr[k]=L[i];
i++;
k++;
}
while(j<n2)
{
arr[k]=R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r)
{
if(l<r)
{
int m=(l+r)/2;
mergeSort(arr,l,m);
mergeSort(arr,m+1,r);
merge(arr,l,m,r);
}
}
void displayArray(int A[],int size)
{
int i;
for(i = 0;i<size;i++)
printf("%d ",A[i]);
printf("\n");
}
