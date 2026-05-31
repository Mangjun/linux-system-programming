#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

static int create_file(void)
{
	FILE *fp;

	if (!(fp = fopen("datafile", "w"))) {
		perror("fopen");
		return -1;
	}

	printf("after fopen(): %ld\n", ftell(fp));

	fputs("hello world\n", fp);
	fputs("hello world!\n", fp);
	fputs("hello world!!\n", fp);
	fputs("hello world!!!\n", fp);

	printf("before fclose(): %ld\n", ftell(fp));

	fclose(fp);

	return 0;
}

static int read_file(void)
{
	FILE *fp;
	char buf[BUF_SIZE];

	memset(buf, 0, sizeof(buf));

	if (!(fp = fopen("datafile", "r+"))) {
		perror("fopen");
		return -1;
	}

	printf("after fopen(): %ld\n", ftell(fp));

	fgets(buf, BUF_SIZE, fp);
	printf("after fgets(): %ld\n", ftell(fp));

	fseek(fp, 0, SEEK_END);
	printf("after fseek(): %ld\n", ftell(fp));

	fputs("final\n", fp);

	printf("before fclose(): %ld\n", ftell(fp));
	fclose(fp);

	return 0;
}

int main(int argc, char **argv)
{
	if (create_file()) {
		perror("create_file");
		return -1;
	}

	if (read_file()) {
		perror("read_file");
		return -1;
	}

	return 0;
}
