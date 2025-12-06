#include <stdio.h>

int main() {
    int frames, n;
    printf("Frames: "); scanf("%d",&frames);
    printf("Length of reference string: "); scanf("%d",&n);
    int ref[n];
    printf("Enter reference string:\n");
    for(int i=0;i<n;i++) scanf("%d",&ref[i]);

    int frame[frames];
    for(int i=0;i<frames;i++) frame[i]=-1;
    int front = 0, faults = 0;

    for(int i=0;i<n;i++){
        int page = ref[i], found=0;
        for(int j=0;j<frames;j++) if(frame[j]==page) {found=1; break;}
        if(!found){
            frame[front] = page;
            front = (front+1)%frames;
            faults++;
        }
        printf("After ref %d: ", page);
        for(int j=0;j<frames;j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total page faults: %d\n", faults);
    return 0;
}


