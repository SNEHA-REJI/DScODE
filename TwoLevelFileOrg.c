#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct file {
    char filename[10];
    struct file *next;
};
struct directory {
    char dirname[10];
    struct directory *next;
    struct file *files;
};
struct directory *root = NULL;
void create_directory();
void delete_directory();
void create_file();
void delete_file();
void search_file();
void display_directories();
void display_files(struct directory *dir);
struct directory* find_directory(char *dname);
int main() {
    int choice = -1;
    do {
        printf("\nROOT MENU\n");
        printf("1. Create Directory\t2. Delete Directory\t3. Create File\t4. Delete File\t5. Search File\t6. Display Directories\t7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_directory(); break;
            case 2: delete_directory(); break;
            case 3: create_file(); break;
            case 4: delete_file(); break;
            case 5: search_file(); break;
            case 6: display_directories(); break;
            case 7: printf("\nExiting\n"); break;
            default: printf("\nINVALID CHOICE\n"); break;
        }
    } while (choice != 7);
    return 0;
}
void create_directory() {
    struct directory *new_dir = (struct directory*)malloc(sizeof(struct directory));
    printf("Enter the directory name: ");
    scanf("%s", new_dir->dirname);
    new_dir->next = NULL;
    new_dir->files = NULL;
    if (root == NULL) {
        root = new_dir;
    } else {
        struct directory *ptr = root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_dir;
    }
    printf("Directory '%s' created.\n", new_dir->dirname);
}
void delete_directory() {
    char dname[10];
    if (root == NULL) {
        printf("No directories available.\n");
        return;
    }
    printf("Enter the directory name to delete: ");
    scanf("%s", dname);
    struct directory *ptr = root, *prev = NULL;
    while (ptr != NULL && strcmp(ptr->dirname, dname)!= 0) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Directory not found.\n");
        return;
    }
    if (prev == NULL) {
        root = ptr->next;
    } else {
        prev->next = ptr->next;
    }
    struct file *file_ptr = ptr->files;
    while (file_ptr != NULL) {
        struct file *temp = file_ptr;
        file_ptr = file_ptr->next;
        free(temp);
    }
    free(ptr);
    printf("Directory '%s' deleted.\n", dname);
}
void create_file() {
    char dname[10];
    printf("Enter the directory name to create file in: ");
    scanf("%s", dname);
    struct directory *dir = find_directory(dname);
    if (dir == NULL) {
        printf("Directory not found.\n");
        return;
    }
    char f_name[10];
    printf("Enter the filename: ");
    scanf("%s", f_name);
    struct file *file_ptr = dir->files;
    while (file_ptr != NULL) {
        if (strcmp(file_ptr->filename, f_name) == 0) {
            printf("File already exists in directory '%s'.\n", dname);
            return;
        }
        file_ptr = file_ptr->next;
    }
    struct file *new_file = (struct file*)malloc(sizeof(struct file));
    strcpy(new_file->filename, f_name);
    new_file->next = NULL;
    if (dir->files == NULL) {
        dir->files = new_file;
    } else {
        file_ptr = dir->files;
        while (file_ptr->next != NULL) {
            file_ptr = file_ptr->next;
        }
        file_ptr->next = new_file;
    }
    printf("File '%s' created in directory '%s'.\n", f_name, dname);
}
void delete_file() {
    char dname[10];
    printf("Enter the directory name to delete file from: ");
    scanf("%s", dname);
    struct directory *dir = find_directory(dname);
    if (dir == NULL) {
        printf("Directory not found.\n");
        return;
    }
    char f_name[10];
    printf("Enter the filename to delete: ");
    scanf("%s", f_name);
    struct file *file_ptr = dir->files, *prev = NULL;
    while (file_ptr != NULL && strcmp(file_ptr->filename, f_name) != 0) {
        prev = file_ptr;
        file_ptr = file_ptr->next;
    }
    if (file_ptr == NULL) {
        printf("File not found.\n");
        return;
    }
    if (prev == NULL) {
        dir->files = file_ptr->next;
    } else {
        prev->next = file_ptr->next;
    }
    free(file_ptr);
    printf("File '%s' deleted from directory '%s'.\n", f_name, dname);
}
void search_file() {
    char dname[10];
    printf("Enter the directory name to search file in: ");
    scanf("%s", dname);
    struct directory *dir = find_directory(dname);
    if (dir == NULL) {
        printf("Directory not found.\n");
        return;
    }
    char f_name[10];
    printf("Enter the filename to search: ");
    scanf("%s", f_name);
    struct file *file_ptr = dir->files;
    while (file_ptr != NULL) {
        if (strcmp(file_ptr->filename, f_name) == 0) {
            printf("File '%s' found in directory '%s'.\n", f_name, dname);
            return;
        }
        file_ptr = file_ptr->next;
    }
    printf("File not found.\n");
}
void display_directories() {
    if (root == NULL) {
        printf("No directories available.\n");
        return;
    }
    struct directory *dir_ptr = root;
    while (dir_ptr != NULL) {
        printf("root/%s->", dir_ptr->dirname);
        display_files(dir_ptr);
        dir_ptr = dir_ptr->next;
    }
}
void display_files(struct directory *dir) {
    if (dir->files == NULL) {
        printf("No files in this directory.\n");
        return;
    }
    struct file *file_ptr = dir->files;
    while (file_ptr != NULL) {
        printf("%s->", file_ptr->filename);
        file_ptr = file_ptr->next;
    }
    printf("NULL\n");
}
struct directory* find_directory(char *dname) {
    struct directory *dir_ptr = root;
    while (dir_ptr != NULL) {
        if (strcmp(dir_ptr->dirname, dname) == 0) {
            return dir_ptr;
        }
        dir_ptr = dir_ptr->next;
    }
    return NULL;
}
