#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int numbytes;
	char *home_dir, filename[80];
	FILE *fp;

	home_dir = getenv("HOME");
	sprintf(filename, "%s/test.log", home_dir);

	if ((fp = fopen(filename, "w")) == NULL) {
		perror("fopen");
		exit(1);
	}

	if ((numbytes = fwrite("getenv test\n", 12, 1, fp)) != 1) {
		perror("fwrite");
	}

	fclose(fp);

	return 0;
}
