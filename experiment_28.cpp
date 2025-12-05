#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[30], line[100], keyword[20];

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Try to open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", filename);
        return 1;
    }

    // Ask keyword to search
    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    printf("\nLines containing '%s':\n", keyword);

    // Read file line by line
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, keyword)) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}


