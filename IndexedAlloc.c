#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL_BLOCKS 100  
int *memory; // Dynamic array to hold memory blocks
struct file {
    char filename[20]; // Increased size to accommodate file extensions
    int index_block;   // Index block of the file
    int blocks[TOTAL_BLOCKS];  // Data blocks allocated to the file
    int block_count;   // Number of blocks allocated
    struct file *next;
};
struct file *root = NULL;
void initialize_memory(int total_blocks);
void create_file(int total_blocks);
void display_files();
int allocate_block(int total_blocks);
void free_block(int block);
int file_exists(char *filename);
int is_valid_filename(const char *filename);
void generate_random_blocks(int *blocks, int count, int total_blocks);
int count_free_blocks(int total_blocks);
int main() {
    int total_blocks;
    printf("Enter the total number of blocks: ");
    scanf("%d", &total_blocks);
    // Allocate memory for memory blocks based on user input
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
    free(memory);  // Free the dynamically allocated memory
    return 0;
}
void initialize_memory(int total_blocks) {
    for (int i = 0; i < total_blocks; i++) {
        memory[i] = 0;  // Set all blocks as free
    }
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
void generate_random_blocks(int *blocks, int count, int total_blocks) {
    int allocated[TOTAL_BLOCKS] = {0}; // To track already allocated blocks
    int block;
    for (int i = 0; i < count; i++) {
        do {
            block = rand() % total_blocks;  // Generate a random block within limits
        } while (allocated[block] || memory[block] != 0);  // Ensure it's free and not already allocated
        allocated[block] = 1;  // Mark this block as allocated
        blocks[i] = block;  // Assign the block
        memory[block] = 1;  // Mark block as allocated
    }
}
void create_file(int total_blocks) {
    struct file *new_file = (struct file*)malloc(sizeof(struct file));
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
    // Allocate random blocks
    generate_random_blocks(new_file->blocks, new_file->block_count, total_blocks);
    // Allocate an index block randomly
    new_file->index_block = rand() % total_blocks;
    while (memory[new_file->index_block] != 0) {  // Ensure index block is free
        new_file->index_block = rand() % total_blocks;
    }
    memory[new_file->index_block] = 1;  // Mark the index block as allocated
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
    printf("File '%s' created with index block %d.\n", new_file->filename, new_file->index_block);
    printf("Data blocks: ");
    for (int i = 0; i < new_file->block_count; i++) {
        printf("%d ", new_file->blocks[i]);
    }
    printf("\n");
}
void display_files() {
    if (root == NULL) {
        printf("No files in the system.\n");
        return;
    }
    printf("\nFile Allocation Table:\n");
    printf("Index\tFile Name\tFile Size\tBlocks Allocated\n");
    printf("----------------------------------------------------\n");
    struct file *ptr = root;
    while (ptr != NULL) {
        printf("%d\t%s\t\t%d\t\t", ptr->index_block, ptr->filename, ptr->block_count);
        for (int i = 0; i < ptr->block_count; i++) {
            printf("%d ", ptr->blocks[i]);
        }
        printf("\n");
        ptr = ptr->next;
    }
}
void free_block(int block) {
    memory[block] = 0;  // Mark block as free
}
