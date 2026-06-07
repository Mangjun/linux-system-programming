#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>

void print_usage(const char *filename)
{
	printf("usage: %s (ex|sh)\n", filename);
	exit(-1);
}

int main(int argc, char **argv)
{
	int fd;
	int ops;

	if (argc != 2) {
		print_usage(argv[0]);
	}

	if (!strncasecmp(argv[1], "sh", 2)) {
		ops = LOCK_SH;
	}
	else if (!strncasecmp(argv[1], "ex", 2)) {
		ops = LOCK_EX;
	}
	else {
		print_usage(argv[0]);
	}

	fd = open("lockfile", O_RDWR | O_CREAT, 0644);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	printf("trying to grab the lock\n");
	if (flock(fd, ops) == -1) {
		perror("flock");
		close(fd);
		return -1;
	}
	printf("grab the lock\n");

	getc(stdin);

	if (flock(fd, LOCK_UN) == -1) {
		perror("flock");
		close(fd);
		return -1;
	}

	close(fd);

	return 0;
}
