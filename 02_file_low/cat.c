#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: %s filename\n", argv[0]);
		exit(1);
	}

	char *filename = argv[1];
	char buf[BUF_SIZE];
	int fd;
	int numbytes;

	memset(buf, 0, BUF_SIZE);

	if ((fd = open(filename, O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	while ((numbytes = read(fd, buf, BUF_SIZE)) != 0) {
		printf("%s\n", buf);
		memset(buf, 0, strlen(buf));
	}

	close(fd);

	return 0;
}
