#include <stdio.h>
#include <string.h>

int main() {
    char dir[10][20];
    int n, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter file name %d: ", i+1);
        scanf("%s", dir[i]);
    }

    printf("\nFiles in directory:\n");
    for(i=0;i<n;i++)
        printf("%s\n", dir[i]);

    return 0;
}


