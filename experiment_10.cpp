#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *msgq;
    char message[100];
    msgq = fopen("msgqueue.txt", "w");
    if(msgq == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }
    strcpy(message, "Hello from parent!");
    fprintf(msgq, "%s", message);
    fclose(msgq);
    printf("Parent sent message to 'msgqueue.txt'\n");
    msgq = fopen("msgqueue.txt", "r");
    if(msgq == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }
    fgets(message, sizeof(message), msgq);
    fclose(msgq);
    printf("Child received message: %s\n", message);

    return 0;
}




