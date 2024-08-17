#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct file {
    char filename[10];
    struct file *next;
};
struct file *p, *head, *tail, *ptr, *prev;
void create_file();
void delete_file();
void search_file();
void display_files();
void main() {
    int choice = -1, ch = -1;
    char d_name[10];
    do {
        printf("\nDIRECTORY MENU\n");
        printf("1. Create Directory\t2. Delete Directory\t3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter the directory name: ");
                scanf("%s", d_name);
                head = NULL;
                ch = -1;
                do {
                    printf("\nFILE MENU\n");
                    printf("1. Create File\t2. Delete File\t3. Search\t4. Display\t5. Exit\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
                    switch (ch) {
                        case 1: create_file(); break;
                        case 2: delete_file(); break;
                        case 3: search_file(); break;
                        case 4: display_files(d_name); break;
                        case 5: printf("\nExiting File Operation\n"); break;
                        default: printf("\nINVALID CHOICE\n"); break;
                    }
                } while (ch != 5);
                break;
            }
            case 2: {
                head = NULL;
                tail = NULL;
                printf("Directory Deleted\n");
                break;
            }
            case 3: {
                printf("\nExiting Directory\n");
                break;
            }
            default: {
                printf("\nINVALID CHOICE\n");
                break;
            }
        }
    } while (choice != 3);
}
void create_file() {
    char f_name[10];
    printf("Enter the filename: ");
    scanf("%s", f_name);
    ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->filename, f_name) == 0) {
            printf("File already exists!\n");
            return;
        }
        ptr = ptr->next;
    }
    p = (struct file*)malloc(sizeof(struct file));
    strcpy(p->filename, f_name);
    p->next = NULL;

    if (head == NULL) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    printf("File created: %s\n", f_name);
}
void delete_file() {
    char f1[10];
    if (head == NULL) {
        printf("Directory is Empty\n");
        return;
    }
    printf("Enter file to be deleted: ");
    scanf("%s", f1);
    ptr = head;
    prev = NULL;
    while (ptr != NULL && strcmp(ptr->filename, f1) != 0) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("File not Found\n");
    } else {
        if (prev == NULL) { // Deleting the first node
            head = ptr->next;
        } else {
            prev->next = ptr->next;
        }
        if (ptr == tail) { // If deleting the last node
            tail = prev;
        }
        free(ptr);
        printf("File Deleted\n");
    }
}
void search_file() {
    char f1[10];
    if (head == NULL) {
        printf("Directory is Empty\n");
        return;
    }
    printf("Enter file to search: ");
    scanf("%s", f1);
    ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->filename, f1) == 0) {
            printf("File Found: %s\n", ptr->filename);
            return;
        }
        ptr = ptr->next;
    }
    printf("File not Found\n");
}
void display_files(char d_name[]) {
    if (head == NULL) {
        printf("Directory is Empty\n");
    } else {
        ptr = head;
        printf("The Directory Details are\n");
        printf("%s->\t", d_name);
        while (ptr != NULL) {
            printf("%s->\t", ptr->filename);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}
