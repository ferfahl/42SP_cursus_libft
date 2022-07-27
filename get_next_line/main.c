#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    get_next_line(fd);
}