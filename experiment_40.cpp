#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[100];
    struct stat fileStat;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) == -1) {
        printf("Error: Cannot access file!\n");
        return 1;
    }

    printf("\nFile permissions cannot be displayed in Windows because\n");
    printf("Linux-style permission bits (rwx for owner/group/others)\n");
    printf("are NOT supported in Windows.\n");

    printf("\nFile size: %ld bytes\n", fileStat.st_size);

    return 0;
}



