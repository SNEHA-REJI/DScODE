#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_BLOCKS 100
int memory[TOTAL_BLOCKS];  // Array representing memory blocks
struct file {
    char filename[10];
    int start_block;
    int length;
    struct file *next;
};
struct file *root = NULL;
int total_blocks;
void initialize_memory();
void create_file();
void display_file_allocation_table();
int find_contiguous_blocks(int length);
int is_valid_filename(char *filename);
int file_exists(char *filename);
int main() {
    printf("Enter total number of blocks: ");
    scanf("%d", &total_blocks);
    initialize_memory();
    char choice;
    do {
        create_file();
        do {
            printf("Do you want to add more files? (Y/N): ");
            scanf(" %c", &choice);
            if (choice != 'Y' && choice != 'N') {
                printf("INVALID CHOICE\n");
            }
        } while (choice != 'Y' && choice != 'N');
        if (choice == 'N') {
            display_file_allocation_table();
            printf("\nExiting\n");
            break;
        }
    } while (choice != 'N');
    return 0;
}
void initialize_memory() {
    for (int i = 0; i < total_blocks; i++) {
        memory[i] = 0;  // Set all blocks as free
    }
}
int is_valid_filename(char *filename) {
    return strchr(filename, '.') != NULL;  // Check if filename contains '.'
}
int file_exists(char *filename) {
    struct file *ptr = root;
    while (ptr != NULL) {
        if (strcmp(ptr->filename, filename) == 0) {
            return 1;  // File already exists
        }
        ptr = ptr->next;
    }
    return 0;  // File does not exist
}
void create_file() {
    struct file *new_file = (struct file*)malloc(sizeof(struct file));
    printf("Enter the filename: ");
    scanf("%s", new_file->filename);
    if (!is_valid_filename(new_file->filename)) {
        printf("Invalid filename! Must contain an extension.\n");
        free(new_file);
        return;
    }
    if (file_exists(new_file->filename)) {
        printf("File already exists!\n");
        free(new_file);
        return;
    }
    printf("Enter the number of blocks: ");
    scanf("%d", &new_file->length);
    int start_block = find_contiguous_blocks(new_file->length);
    if (start_block == -1) {
        printf("File cannot be allocated!\n");
        free(new_file);
        return;
    }
    new_file->start_block = start_block;
    new_file->next = NULL;
    for (int i = start_block; i < start_block + new_file->length; i++) {
        memory[i] = 1;
    }
    if (root == NULL) {
        root = new_file;
    } else {
        struct file *ptr = root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_file;
    }
    printf("File '%s' created, starting at block %d and occupying %d blocks.\n", new_file->filename, new_file->start_block, new_file->length);
}
void display_file_allocation_table() {
    printf("\nFile Allocation Table:\n");
    printf("Filename\tSize\tBlocks Allocated\n");
    printf("--------\t----\t----------------\n");
    struct file *ptr = root;
    while (ptr != NULL) {
        printf("%s\t\t%d\t\t", ptr->filename, ptr->length);
        for (int i = ptr->start_block; i < ptr->start_block + ptr->length; i++) {
            printf("%d ", i);
        }
        printf("\n");
        ptr = ptr->next;
    }
}
int find_contiguous_blocks(int length) {
    int free_count = 0;
    int start_block = -1;
    for (int i = 0; i < total_blocks; i++) {
        if (memory[i] == 0) {
            if (start_block == -1) {
                start_block = i;
            }
            free_count++;
            if (free_count == length) {
                return start_block;
            }
        } else {
            free_count = 0;
            start_block = -1;
        }
    }
    return -1;  // No sufficient contiguous blocks found
}
