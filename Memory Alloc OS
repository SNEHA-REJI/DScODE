#include <stdio.h>
#include <stdlib.h>
// Structure for process node
struct Process {
    int size;
    struct Process* next;
};
// Structure for block node
struct Block {
    int size;
    struct Block* next;
};
// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};
void displayLinkedList(struct Node* head);
struct Node* createLinkedList(int n);
int* linkedListToArray(struct Node* head, int n);
void main() {
    struct Node* processHead = NULL;
    struct Node* blockHead = NULL;
    int np, nb, ch, i, j, unusedSpace = 0;
    printf("Enter the no. of process: ");
    scanf("%d", &np);
    printf("Enter the no. of blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of each process:\n");
    processHead = createLinkedList(np);
    printf("Enter the block sizes:\n");
    blockHead = createLinkedList(nb);
    // Convert linked list inputs to arrays
    int *p = linkedListToArray(processHead, np);
    int *b = linkedListToArray(blockHead, nb);
    int *c = linkedListToArray(blockHead, nb);
    int *d = linkedListToArray(blockHead, nb);
    int alloc[10], flag[10] = {0}, bflag[10] = {0};
    if (np <= nb) {
        printf("1.First fit\n2.Best fit\n3.Worst fit\n4.Exit\n");
        do {
            printf("\nEnter your choice: ");
            scanf("%d", &ch);
            switch (ch) {
            case 1:
                unusedSpace = 0;
                printf("\nFirst Fit\n");
                for (i = 0; i < np; i++) {
                    for (j = 0; j < nb; j++) {
                        if (bflag[j] == 0 && p[i] <= b[j]) {
                            alloc[j] = p[i];
                            printf("\nAlloc[%d]", alloc[j]);
                            printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, b[j]);
                            flag[i] = 0, bflag[j] = 1, b[j] -= p[i];
                            break;
                        } else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < np; i++) {
                    if (flag[i] != 0)
                        printf("\nProcess %d of size %d is not allocated:", i, p[i]);
                }
                for (i = 0; i < nb; i++) {
                    unusedSpace += b[i];
                }
                printf("\nTotal unused space: %d\n", unusedSpace);
                break;
            case 2:
                unusedSpace = 0;
                printf("\nBest Fit\n");
                // Implement Best Fit
                   for (i = 0; i < nb; i++)
                {
                    for (j = i + 1; j < nb; j++)
                    {
                        if (c[i] > c[j])
                        {
                            int temp = c[i];
                            c[i] = c[j];
                            c[j] = temp;
                        }
                    }
                }
                printf("\nAfter sorting block sizes:");
                for (i = 0; i < nb; i++)
                    printf("\nBlock %d:%d", i, c[i]);
                for (i = 0; i < np; i++)
                {
                    for (j = 0; j < nb; j++)
                    {
                        if (p[i] <= c[j])
                        {
                            alloc[j] = p[i];
                            printf("\nAlloc[%d]", alloc[j]);
                            printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, c[j]);
                            flag[i] = 0, c[j] -= p[i];
                            break;
                        }
                        else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < np; i++)
                {
                    if (flag[i] != 0)
                        printf("\nProcess %d of size %d is not allocated", i, p[i]);
                }
                for (i = 0; i < nb; i++)
                {
                    unusedSpace += c[i];
                }
                printf("\nTotal unused space: %d\n", unusedSpace);
                break;
            case 3:
                unusedSpace = 0;
                printf("\nWorst Fit\n");
                // Implement Worst Fit
                  for (i = 0; i < nb; i++)
                {
                    for (j = i + 1; j < nb; j++)
                    {
                        if (d[i] < d[j])
                        {
                            int temp = d[i];
                            d[i] = d[j];
                            d[j] = temp;
                        }
                    }
                }
                printf("\nAfter sorting block sizes:");
                for (i = 0; i < nb; i++)
                    printf("\nBlock %d:%d", i, d[i]);
                for (i = 0; i < np; i++)
                {
                    for (j = 0; j < nb; j++)
                    {
                        if (p[i] <= d[j])
                        {
                            alloc[j] = p[i];
                            printf("\nAlloc[%d]", alloc[j]);
                            printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, d[j]);
                            flag[i] = 0, d[j] -= p[i];
                            break;
                        }
                        else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < np; i++)
                {
                    if (flag[i] != 0)
                        printf("\nProcess %d of size %d is not allocated", i, p[i]);
                }
                for (i = 0; i < nb; i++)
                {
                    unusedSpace += d[i];
                }
                printf("\nTotal unused space: %d\n", unusedSpace);
                break;
            case 4:
                printf("Exiting program!!...");
                break;
            default:
                printf("Invalid Choice");
                break;
            }
        } while (ch != 4);
    }
}
// Function to create a linked list with n nodes
struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* p = NULL;
    int data;
   
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory allocation failed");
            break;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;
       
        if (head == NULL) {
            head = temp;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
int* linkedListToArray(struct Node* head, int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    struct Node* temp = head;
    int i = 0;
   
    while (temp != NULL) {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    return arr;
}

