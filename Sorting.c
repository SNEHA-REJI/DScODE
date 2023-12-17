
#include<stdio.h>
void bubbleS(int B[50],int n);
void insertionS(int B[50],int n);
void selectionS(int B[50],int n);
void main()
{
    int choice;
    do
    {
       int n,A[50],B[50],i;
       printf("\nMENU\n");
       printf("1.Inserting Array\t2.Perform Bubble Sort\t3.Perform Insertion Sort\t4.Perform Selection Sort\t5.Exit\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               printf("Enter the number of terms in the array\n");
               scanf("%d",&n);
               printf("Enter the elements in the array\n");
               for(i=0;i<n;i++)
               {
                scanf("%d",&A[i]);
               }
               break;
           }
           case 2:
           {
               for(i=0;i<n;i++)
               {
                B[i]=A[i];
               }
               bubbleS(B,n);
               break;
           }
           case 3:
           {
               for(i=0;i<n;i++)
               {
                B[i]=A[i];
               }
               insertionS(B,n);
               break;
           }
            case 4:
           {
               for(i=0;i<n;i++)
               {
                B[i]=A[i];
               }
               selectionS(B,n);        
               break;
           }
           case 5:
           {
                printf("Exiting Sorting program\n");
                break;
           }
           default:
           {
               printf("INVALID CHOICE");
               break;
           }
       }
    }
    while(choice!=5);
}
void bubbleS(int B[50],int n)
{
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(B[j]>B[j+1])
            {
                temp=B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
            }
            printf("%d\t",B[j]);
        }
        printf("%d\n",B[j]);
    }
    printf("Array after performing Bubble Sort\n");
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
       printf("%d\t",B[i]);
    }
}
void insertionS(int B[50],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=B[i];
        printf("Key at pass %d=%d\n",i,key);
        j=i-1;
        while(j>=0 && key<=B[j])
        {
            B[j+1]=B[j];
            j=j-1;
        }
        B[j+1]=key;
    }
    printf("Array after performing Inserion Sort\n");
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
       printf("%d\t",B[i]);
    }
}
void selectionS(int B[50],int n)
{
    int pass,j,min_index,temp;
    for(pass=0;pass<n-1;pass++)
    {
        min_index=pass;
        for(j=pass+1;j<n;j++)
        {
            if(B[j]<B[min_index])
            {
                min_index=j;
            }
        }
        printf("min_index=%d\n",min_index);
        temp=B[pass];
        B[pass]=B[min_index];
        B[min_index]=temp;
    }
    printf("Array after performing Selection Sort\n");
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
       printf("%d\t",B[i]);
    }
}

