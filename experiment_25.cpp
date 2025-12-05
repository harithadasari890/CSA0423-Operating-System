#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    struct stat s;
    DIR *d;
    struct dirent *de;

    stat("myfile.txt", &s);
    printf("File Size: %ld bytes\n", s.st_size);

    d = opendir(".");
    printf("\nDirectory Contents:\n");
    while ((de = readdir(d)) != NULL)
        printf("%s\n", de->d_name);

    closedir(d);
    return 0;
}

