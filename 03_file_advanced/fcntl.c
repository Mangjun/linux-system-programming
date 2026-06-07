#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv)
{
	char buf[128] = {0};
	int numbytes;
	int flag;
	int fd;

	fd = STDIN_FILENO;

	numbytes = read(fd, buf, sizeof(buf));
	if (numbytes < 0) {
		perror("read");
		return -1;
	}
	else if (numbytes == 0) {
		printf("data is not exist\n");
		return -1;
	}

	printf("%s -  %dbytes\n", buf, numbytes);

	flag = fcntl(fd, F_GETFL);
	if (flag == -1) {
		perror("fcntl");
		printf("[%d] - %s\n", errno, strerror(errno));
		return -1;
	}

	if (fcntl(fd, F_SETFL, flag | O_NONBLOCK) == -1) {
		perror("fcntl");
		printf("[%d] - %s\n", errno, strerror(errno));
		return -1;
	}

	numbytes = read(fd, buf, sizeof(buf));
	if (numbytes < 0) {
		perror("read");
		return -1;
	}
	else if (numbytes == 0) {
		printf("data is not exist\n");
		return -1;
	}

	printf("%s -  %dbytes\n", buf, numbytes);

	return 0;
}
