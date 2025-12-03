#include <stdio.h>

int main() {
    int users, files, i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i=1;i<=users;i++) {
        printf("\nUser %d directory:\n", i);
        printf("Enter number of files: ");
        scanf("%d", &files);

        char fname[files][20];
        for(j=0;j<files;j++) {
            printf("File %d: ", j+1);
            scanf("%s", fname[j]);
        }

        printf("Files of User %d:\n", i);
        for(j=0;j<files;j++)
            printf("%s\n", fname[j]);
    }
    return 0;
}



