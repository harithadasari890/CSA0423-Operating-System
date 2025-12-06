#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int f) {
    int farthest = index, pos = -1;
    for (int i = 0; i < f; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int pages[30], frames[10], n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++) frames[i] = -1;

    int faults = 0;

    printf("\nPage\tFrames\n");
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < f; j++)
            if (frames[j] == pages[i]) flag = 1;

        if (!flag) {
            int pos = findOptimal(pages, frames, n, i + 1, f);
            frames[pos] = pages[i];
            faults++;
        }

        printf("%d\t", pages[i]);
        for (int j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

