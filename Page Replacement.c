#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAMES 20
#define MAX_PAGES 50
void FIFO(int pages[], int n, int frames);
void LRU(int pages[], int n, int frames);
int main() {
    int pages[MAX_PAGES];
    int n, frames, choice;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    do{
    printf("Choose Page Replacement Algorithm:\n");
    printf("1. FIFO\t2. LRU\t3. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            FIFO(pages, n, frames);
            break;
        case 2:
            LRU(pages, n, frames);
            break;
        case 3:
            printf("Exiting Program!!");
            break;
        default:
            printf("Invalid choice\n");
            break;
    } }while(choice!=3);

    return 0;
}
void FIFO(int pages[], int n, int frames) {
    int frame[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;
    printf("FIFO Page Replacement Algorithm\n");
    for(int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
    }
    for(int i = 0; i < n; i++) {
        int page = pages[i];
        int pageExists = 0;
        for(int j = 0; j < frames; j++) {
            if(frame[j] == page) {
                pageExists = 1;
                break;
            }
        }
        if(!pageExists) {
            frame[frameIndex] = page;
            frameIndex = (frameIndex + 1) % frames;
            pageFaults++;
        }
        printf("Page %d: ", page);
        for(int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}
void LRU(int pages[], int n, int frames) {
    int frame[MAX_FRAMES];
    int counter[MAX_FRAMES] = {0};
    int pageFaults = 0;
    printf("LRU Page Replacement Algorithm\n");
    for(int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
    }
    for(int i = 0; i < n; i++) {
        int page = pages[i];
        int pageExists = 0;
        for(int j = 0; j < frames; j++) {
            if(frame[j] == page) {
                pageExists = 1;
                counter[j] = i + 1; 
                break;
            }
        }
        if(!pageExists) {
            int minCounterIndex = 0;
            for(int j = 1; j < frames; j++) {
                if(counter[j] < counter[minCounterIndex]) {
                    minCounterIndex = j;
                }
            }
            frame[minCounterIndex] = page;
            counter[minCounterIndex] = i + 1; // Update page access time
            pageFaults++;
        }
      printf("Page %d: ", page);
        for(int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        } 
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}
