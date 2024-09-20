#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL_BLOCKS 100  
int *memory;
struct block {
    int block_number;      
    struct block *next;    
};
struct file {
    char filename[20];    
    struct block *head;    
    int block_count;      
    struct file *next;
};
struct file *root = NULL;
void initialize_memory(int total_blocks);
void create_file(int total_blocks);
void display_files();
void generate_linked_blocks(struct block **head, int count, int total_blocks);
int count_free_blocks(int total_blocks);
int file_exists(char *filename);
int is_valid_filename(const char *filename);
int main() {
    int total_blocks;
    printf("Enter the total number of blocks: ");
    scanf("%d", &total_blocks);
    memory = (int *)malloc(total_blocks * sizeof(int));  
    srand(time(NULL));  // Seed for random number generation
    initialize_memory(total_blocks);
    char choice;
    do {
        printf("Do you want to create a file? (Y/N): ");
        scanf(" %c", &choice);  // Space before %c to ignore any whitespace
        if (choice == 'Y' || choice == 'y') {
            create_file(total_blocks);
        } else if (choice == 'N' || choice == 'n') {
            printf("Exiting...\n");
        } else {
            printf("INVALID CHOICE! Please enter Y or N.\n");
     

   }
    } while (choice != 'N' && choice != 'n');
    display_files();
    free(memory);  
    return 0;
}
void initialize_memory(int total_blocks) {
    for (int i = 0; i < total_blocks; i++) {
        memory[i] = 0;  
    }
}
int file_exists(char *filename) {
    struct file *ptr = root;
    while (ptr != NULL) {
        if (strcmp(ptr->filename, filename) == 0) {
            return 1;  
        }
        ptr = ptr->next;
    }
    return 0;  // File does not exist
}
int is_valid_filename(const char *filename) {
    return strchr(filename, '.') != NULL;
}
int count_free_blocks(int total_blocks) {
    int free_count = 0;
    for (int i = 0; i < total_blocks; i++) {
        if (memory[i] == 0) {
            free_count++;  // Count free blocks
        }
    }
    return free_count;
}
void generate_linked_blocks(struct block **head, int count, int total_blocks) {
    struct block *current = NULL;
    for (int i = 0; i < count; i++) {
        struct block *new_block = (struct block *)malloc(sizeof(struct block));
        int block_number;
        do {
            block_number = rand() % total_blocks;  // Generate a random block number
        } while (memory[block_number] != 0);  // Ensure the block is free
        memory[block_number] = 1;  // Mark the block as allocated
        new_block->block_number = block_number;
        new_block->next = NULL;
        if (*head == NULL) {
            *head = new_block;  // First block in the file
        } else {
            current->next = new_block;  // Link the previous block to this one
        }
        current = new_block;
    }
}
void create_file(int total_blocks) {
    struct file *new_file = (struct file *)malloc(sizeof(struct file));
    printf("Enter the filename (with extension): ");
    scanf("%s", new_file->filename);
    if (!is_valid_filename(new_file->filename)) {
        printf("Error: Invalid filename! Filename must contain an extension (e.g., .txt).\n");
        free(new_file);
        return;
    }
    if (file_exists(new_file->filename)) {
        printf("Error: File already exists!\n");
        free(new_file);
        return;
    }
    printf("Enter the file size (in blocks): ");
    scanf("%d", &new_file->block_count);
    int free_blocks = count_free_blocks(total_blocks);
    if (new_file->block_count > free_blocks) {
        printf("Error: File size exceeds available free blocks. File cannot be allocated.\n");
        free(new_file);
        return;
    }
    new_file->head = NULL;
    generate_linked_blocks(&new_file->head, new_file->block_count, total_blocks);
    new_file->next = NULL;
    if (root == NULL) {
        root = new_file;
    } else {
        struct file *ptr = root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_file;
    }
    printf("File '%s' created.\n", new_file->filename);
}
void display_files() {
    if (root == NULL) {
        printf("No files in the system.\n");
        return;
    }
    printf("\nFile Allocation Table:\n");
    printf("File Name\tFile Size\tBlocks Allocated (Linked)\n");
    printf("--------------------------------------------------------\n");
    struct file *ptr = root;
    while (ptr != NULL) {
        printf("%s\t\t%d\t\t", ptr->filename, ptr->block_count);
        struct block *block_ptr = ptr->head;
        while (block_ptr != NULL) {
            if (block_ptr->next != NULL) {
                printf("%d -> ", block_ptr->block_number);
            } else {
                printf("%d", block_ptr->block_number);
            }
            block_ptr = block_ptr->next;
        }
        printf("\n");
        ptr = ptr->next;
    }
}
