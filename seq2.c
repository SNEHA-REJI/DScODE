#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_BLOCKS 100
#define MAX_FILES 10
int memory[TOTAL_BLOCKS];
struct file{
    char filename[10];
    int start_block;
    int length;
};
struct file files[MAX_FILES];
int total_files=0;
int total_blocks;
void initialize_memory();
void create_file();
void display_file_allocation_table();
int find_contiguous_blocks(int length);
int is_valid_filename(char *filename);
int file_exists(char *filename);
int main(){
    printf("Enter total number of blocks: ");
    scanf("%d",&total_blocks);
    initialize_memory();
    char choice;
    do{
        create_file();
        do{
            printf("Do you want to add more files? (Y/N): ");
            scanf(" %c",&choice);
            if(choice!='Y'&&choice!='N'){
                printf("INVALID CHOICE\n");
            }
        }while(choice!='Y'&&choice!='N');
        if(choice=='N'){
            display_file_allocation_table();
            printf("\nExiting\n");
            break;
        }
    }while(choice!='N');
    return 0;
}
void initialize_memory(){
    for(int i=0;i<total_blocks;i++){
        memory[i]=0;
    }
}
int is_valid_filename(char *filename){
    return strchr(filename,'.')!=NULL;
}
int file_exists(char *filename){
    for(int i=0;i<total_files;i++){
        if(strcmp(files[i].filename,filename)==0){
            return 1;
        }
    }
    return 0;
}
void create_file(){
    if(total_files>=MAX_FILES){
        printf("Maximum file limit reached!\n");
        return;
    }
    struct file new_file;
    printf("Enter the filename: ");
    scanf("%s",new_file.filename);
    if(!is_valid_filename(new_file.filename)){
        printf("Invalid filename! Must contain an extension.\n");
        return;
    }
    if(file_exists(new_file.filename)){
        printf("File already exists!\n");
        return;
    }
    printf("Enter the number of blocks: ");
    scanf("%d",&new_file.length);
    int start_block=find_contiguous_blocks(new_file.length);
    if(start_block==-1){
        printf("File cannot be allocated!\n");
        return;
    }
    new_file.start_block=start_block;
    for(int i=start_block;i<start_block+new_file.length;i++){
        memory[i]=1;
    }
    files[total_files++]=new_file;
    printf("File '%s' created, starting at block %d and occupying %d blocks.\n",new_file.filename,new_file.start_block,new_file.length);
}
void display_file_allocation_table(){
    printf("\nFile Allocation Table:\n");
    printf("Filename\tSize\tBlocks Allocated\n");
    printf("--------\t----\t----------------\n");
    for(int i=0;i<total_files;i++){
        printf("%s\t\t%d\t\t",files[i].filename,files[i].length);
        for(int j=files[i].start_block;j<files[i].start_block+files[i].length;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
}
int find_contiguous_blocks(int length){
    int free_count=0,start_block=-1;
    for(int i=0;i<total_blocks;i++){
        if(memory[i]==0){
            if(start_block==-1){
                start_block=i;
            }
            free_count++;
            if(free_count==length){
                return start_block;
            }
        }else{
            free_count=0;
            start_block=-1;
        }
    }
    return -1;
}
