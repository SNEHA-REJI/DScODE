#include<stdio.h>
#include<stdbool.h>
void findSafeSequence(int p,int r,char pname[p][10],int alloc[p][r],int need[p][r],int avail[r],int safe[]) {
    int i;
    int finish[p];
    int need_resources[r];
    for(int k=0;k<p;k++) { // Initialize finish array
      finish[k]=0;
    }
    for(int k=0;k<r;k++) {
      need_resources[k]=avail[k];
    }
    int ind=0;
    int deadlock_count=0;
    bool deadlock[p]; // Flag to track processes contributing to deadlock
    while(ind<p) {
      bool found=false;
      for(int i=0;i<p;i++) {
       if(!finish[i]) {
        bool flag=true;
        for(int j=0;j<r;j++) {
         if(need[i][j]>need_resources[j]) {
            flag=false;
            break;
    }   }
      if(flag) {   // Process can be executed
       safe[ind++]=i;
       finish[i]=1;
       for(int j=0;j<r;j++) {  
         need_resources[j]+=alloc[i][j];
        }
       found=true;
      }
    } }
    if(!found) {  // Check for deadlock
      deadlock[deadlock_count++]=true;
      printf("Deadlock detected at process %s\n",pname[ind]);
      break;
    } }
    if(deadlock_count==0) {  // No deadlock found, print safe sequence
      printf("\nSafe sequence is: < ");
      for(int i=0;i<p-1;i++) {
        printf("%s,",pname[safe[i]]);
      }
      printf("%s >\n",pname[safe[p-1]]);
    }
    else {  // Print processes contributing to deadlock
    printf("\nProcesses contributing to deadlock:\n");
    for (int i=0;i<deadlock_count;i++) {
       printf("%s ",pname[deadlock[i]]);
    }
    printf("\n");
    }
}
int main() {
    int p,r,k,i,j;
    printf("Enter the no. of processes\n");
    scanf("%d",&p);
    printf("Enter the no. of resources\n");
    scanf("%d",&r);
    char pname[p][10]; // Assuming process names are strings of maximum length 10
    int alloc[p][r],max[p][r],need[p][r],avail[r],safe[p];
    for(k=0;k<p;k++) {
        printf("Enter the name of process %d: ",k + 1);
        scanf("%s",pname[k]);
    }
    printf("Enter the Allocation matrix\n");
    for(i=0;i<p;i++) {
        for(j=0;j<r;j++) {
          scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Maximum Need matrix\n");
    for(i=0;i<p;i++) {
        for(j=0;j<r;j++) {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the Available Resources\n");
    for(j=0;j<r;j++) {
        scanf("%d",&avail[j]);
    }
    printf("Allocation matrix:\n");
    for(i=0;i<p;i++) {
        for(j=0;j<r;j++) {
            printf("%d\t",alloc[i][j]);
        }
        printf("\n");
    }
    printf("Maximum matrix:\n");
    for(i=0;i<p;i++) {
        for(j=0;j<r;j++) {
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("Availability:\n");
    for(j=0;j<r;j++) {
        printf("%d\t", avail[j]);
    }
    printf("\n");
    printf("Need matrix:\n");
    for(i=0;i<p;i++) {
        for(j=0;j<r;j++) {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    findSafeSequence(p,r,pname,alloc,need,avail,safe);
    return 0;
}

