#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[30], frames[10], time[10];
    int n, f, i, j, pos, counter = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++) {
        int flag = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag = 1;
            }
        }

        if (flag == 0) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    counter++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    faults++;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            pos = findLRU(time, f);
            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

