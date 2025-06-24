#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd;
    int c;

    fd = open("test.txt", O_RDONLY);
    while(1) {
        c = ft_getc(fd);
        if (c == EOF) {
            break;
        }
        printf("%c", c);
    }
    close(fd);
    return (0);
}