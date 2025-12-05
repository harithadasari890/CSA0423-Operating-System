#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd;
    char buffer[50];
    int n;
    fd = open("input.txt", O_RDONLY);
    if (fd < 0) {
        printf("Cannot open input.txt\n");
        return 1;
    }
    n = read(fd, buffer, sizeof(buffer)-1); // leave space for null
    buffer[n] = '\0'; // null terminate string
    printf("File Content: %s\n", buffer);
    close(fd);

    int out = open("output.txt", O_WRONLY | O_CREAT, 0644);
    write(out, buffer, n);
    close(out);

    printf("File written to output.txt successfully.\n");
    return 0;
}

