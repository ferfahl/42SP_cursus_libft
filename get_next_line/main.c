#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *print;

	fd = open("test.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("1st GNL return: %s", print);
	free(print);
	print = get_next_line(fd);
	printf("2nd GNL return: %s", print);
	free(print);
	print = get_next_line(fd);
	printf("3rd GNL return: %s", print);
	free(print);
	print = get_next_line(fd);
	printf("4th GNL return: %s", print);
	free(print);
	print = get_next_line(fd);
	printf("5th GNL return: %s", print);
	
}