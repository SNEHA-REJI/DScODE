#include <stdio.h>
#include <stdlib.h>
int hashTable[100]; 
int linearProbe(int key,int size);
int quadraticProbe(int key,int size);
void displayHashTable(int size);
void main() 
{
    int size;
    printf("Name: Kesiya Mariam Reji\nBranch: CS-B\nRoll No.: 54\n");
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    printf("Initializing all values of the hash table as -1\n");
    for (int i=0;i<size;i++) 
    {
        hashTable[i]=-1;
    }
    int choice, key;
    do 
    {
        printf("\nMenu:\n");
        printf("1.Insert with Linear Probing\n");
        printf("2.Insert with Quadratic Probing\n");
        printf("3.Display Hash Table\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) 
        {
            case 1:
            {
                int s;
                printf("Enter number of elements to be inserted: ");
                scanf("%d",&s);
                if(s<=size)
                {
                for(int i=0;i<s;i++)
                {
                printf("Enter key to insert: ");
                scanf("%d",&key);
                linearProbe(key,size);
                }
                }
                else
                printf("Invalid Number of Elements");
                break;
            }
            case 2:
            {
                int s;
                printf("Enter number of elements to be inserted: ");
                scanf("%d",&s);
                if(s<=size)
                {
                for(int i=0;i<s;i++)
                {
                printf("Enter key to insert: ");
                scanf("%d",&key);
                quadraticProbe(key,size);
                }
                }
                else
                printf("Invalid Number of Elements");
                break;
            }
            case 3:
            {
                displayHashTable(size);
                for (int i=0;i<size;i++) 
                {
                    hashTable[i]=-1;
                }
                break;
            }
            case 4:
            {
                printf("Exiting Hashing Program..\n");
                break;
            }
            default:
            {
                printf("INVALID CHOICE\n");
            }
        }
    } 
    while (choice != 4);
}

int linearProbe(int key,int size) 
{
    int index=key%size;
    while(hashTable[index]!=-1)
    {
        index=(index+1)%size;
    }
    hashTable[index]=key;
    return index;
}

int quadraticProbe(int key,int size) 
{
    int i=0;
    int index=(key+i*i)%size;
    while(hashTable[index]!=-1)
    {
        i++;
        index=(key+i*i)%size;
    }
    hashTable[index]=key;
    return index;
}
void displayHashTable(int size) 
{
    printf("Hash Table:\n");
    for (int i=0;i<size;i++) 
    {
        printf("%d: %d\n",i,hashTable[i]);
    }
    printf("Hash Table becomes empty");
}
