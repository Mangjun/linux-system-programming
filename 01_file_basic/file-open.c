#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int write_to_file(void)
{
	FILE *fp;

	fp = fopen("data", "w");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}

	fputs("hello world...", fp);
	fclose(fp);

	return 0;
}

int read_from_file(void)
{
	FILE *fp;
	char buf[BUF_SIZE];

	memset(buf, 0, sizeof(buf));

	fp = fopen("data", "r");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}

	fgets(buf, BUF_SIZE, fp);
	printf("buf: %s\n", buf);

	return 0;
}

int main(int argc, char **argv)
{
	if (write_to_file()) {
		perror("write_to_file");
		return -1;
	}

	if (read_from_file()) {
		perror("read_from_file");
		return -1;
	}

	return 0;
}
