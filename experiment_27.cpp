#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {
        printf("Cannot open directory.\n");
        return 1;
    }

    printf("Text files in current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and folders
        if (entry->d_name[0] != '.' && strstr(entry->d_name, ".txt") != NULL) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}


