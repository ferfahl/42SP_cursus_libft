#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *print;

    fd = open(argv[1], O_RDONLY);
    print = get_next_line(fd);
    printf("%s", print);
}