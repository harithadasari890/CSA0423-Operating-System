#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char data[100];
    fp = fopen("shared.txt", "w");
    if(fp == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }
    strcpy(data, "Hello from parent!");
    fprintf(fp, "%s", data);
    fclose(fp);
    printf("Parent wrote to 'shared.txt'\n");

    // Child process reads data
    fp = fopen("shared.txt", "r");
    if(fp == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }
    fgets(data, sizeof(data), fp);
    fclose(fp);
    printf("Child reads from 'shared.txt': %s\n", data);

    return 0;
}


