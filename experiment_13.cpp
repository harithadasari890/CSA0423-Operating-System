#include <stdio.h>

int main() {
    int block[3] = {100, 500, 200};
    int process[3] = {120, 50, 200};
    int i, j;

    printf("First Fit Allocation:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(block[j] >= process[i]) {
                printf("Process %d -> Block %d\n", i+1, j+1);
                block[j] -= process[i];
                break;
            }
        }
    }
    return 0;
}


