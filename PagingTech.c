#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process {
    char p_name[5];
    int p_size;
    int frames_allocated[10]; 
    int frame_count;
    int internal_frag;
};
struct process processes[15];
int process_count = 0;  
int total_memory, frame_size, total_frames, available_frames;
int total_internal_frag = 0; 
int frame_table[50]; 
void display_PCB() {
    printf("\nProcess Control Block\n");
    printf("------------------------------------------------------------\n");
    printf("Process ID\tProcess Size\tFrames Allocated\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("%s\t\t%d\t\t", processes[i].p_name, processes[i].p_size);
        for (int j = 0; j < processes[i].frame_count; j++) {
            printf("%d ", processes[i].frames_allocated[j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------\n");
    printf("Total Internal Fragmentation: %d\n", total_internal_frag);
}
void insert_process() {
    char name[5];
    int size;
    printf("Enter the process id: ");
    scanf("%s", name);
    printf("Enter the process size: ");
    scanf("%d", &size);
    int required_frames = (size + frame_size - 1) / frame_size; 
    if (required_frames > available_frames) {
        printf("Memory Full\n");
        return;
    }
    struct process *p = &processes[process_count];  
    strcpy(p->p_name, name);
    p->p_size = size;
    p->frame_count = required_frames;
    p->internal_frag = (frame_size * required_frames) - size;  
    total_internal_frag += p->internal_frag;  
    printf("Process allocated\n");
    for (int i = 0; i < required_frames; i++) {
        int random_frame;
        do {
            random_frame = rand() % total_frames;  
        } while (frame_table[random_frame] == 1);  
        p->frames_allocated[i] = random_frame;
        frame_table[random_frame] = 1;  
        available_frames--;
    }
    printf("Internal Fragmentation: %d\n",total_internal_frag);
    process_count++;
}
void delete_process() {
    char p1[5];
    if (process_count == 0) {
        printf("No process exists.\n");
        return;
    }
    printf("Enter the process id: ");
    scanf("%s", p1);
    int index = -1;
    for (int i = 0; i < process_count; i++) {
        if (strcmp(processes[i].p_name, p1) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Process not found\n");
    } else {
        available_frames += processes[index].frame_count;
        total_internal_frag -= processes[index].internal_frag;  
        for (int i = index; i < process_count - 1; i++) {
            processes[i] = processes[i + 1];
        }
        process_count--;
        printf("Process deleted\n");
        printf("Internal Fragmentation: %d\n", total_internal_frag);
    }
}
int main() {
    printf("Enter the total memory (in Kb): ");
    scanf("%d", &total_memory);
    printf("Enter the frame size (in Kb): ");
    scanf("%d", &frame_size);
    total_frames = total_memory / frame_size;
    available_frames = total_frames;
    printf("Total No.of Frames available: %d\n", total_frames);
    int choice = -1;
    do {
        printf("\nMenu\n");
        printf("1. Insert\t2. Delete\t3. Display PCB\t4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                insert_process();
                break;
            }
            case 2: {
                delete_process();
                break;
            }
            case 3: {
                display_PCB();
                break;
            }
            case 4: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nINVALID CHOICE\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}
