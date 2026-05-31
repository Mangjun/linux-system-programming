#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static int append_file(void)
{
	int fd;

	fd = open("datafile", O_WRONLY | O_APPEND);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	dprintf(fd, "hello again!\n");

	close(fd);

	return 0;
}

static int trunc_file(void)
{
	int fd;

	fd = open("datafile", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	dprintf(fd, "byebye file\n");

	close(fd);

	return 0;
}

static int write_file(void)
{
	int fd;

	fd = open("datafile", O_WRONLY | O_CREAT, 0644);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	dprintf(fd, "hello world!! %d\n", 123);

	close(fd);

	return 0;
}

int main(int argc, char **argv)
{
	if (write_file()) {
		perror("write_file");
		return -1;
	}

	if (trunc_file()) {
		perror("trunc_file");
		return -1;
	}

	if (append_file()) {
		perror("append_file");
		return -1;
	}

	return 0;
}
