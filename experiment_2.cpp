#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char src[100], dest[100];
    int s, d, n;
    char buffer[1024];

    printf("Enter source file name: ");
    scanf("%s", src);

    printf("Enter destination file name: ");
    scanf("%s", dest);

    s = open(src, O_RDONLY);  // Open source file for reading
    if(s < 0) {
        printf("Cannot open source file!\n");
        return 1;
    }

    d = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open destination file for writing
    if(d < 0) {
        printf("Cannot open destination file!\n");
        close(s);
        return 1;
    }

    // Copy contents
    while((n = read(s, buffer, sizeof(buffer))) > 0) {
        write(d, buffer, n);
    }

    printf("File copied successfully!\n");

    close(s);
    close(d);

    return 0;
}


