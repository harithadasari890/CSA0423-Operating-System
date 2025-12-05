#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[50];

    fd = open("myfile.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello OS!", 10);

    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 10);

    printf("Content Read: %s\n", buffer);

    close(fd);
    return 0;
}

