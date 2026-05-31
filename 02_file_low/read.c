#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct person {
	char name[20];
	int age;
};

static int write_info(struct person *p)
{
	int fd;
	ssize_t res;

	fd = open("person_info", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	res = write(fd, p, sizeof(struct person));

	if (res == -1) {
		perror("write");
		goto err;	
	}
	else if (res != sizeof(struct person)) {
		perror("partial write");
		goto err;
	}

	close(fd);

	return 0;

err:
	if (fd > 0) {
		close(fd);
	}

	return -1;
}

static int dump_info(void)
{
	int fd;
	struct person p;
	ssize_t res;

	fd = open("person_info", O_RDONLY);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	do {
		res = read(fd, &p, sizeof(struct person));

		if (res == -1) {
			perror("read");
			goto err;
		}
		else if (res == 0) {
			FILE *fp;
			fp = fdopen(fd, "r");

			if (!fp) {
				perror("fdopen");
				goto err;
			}

			printf("file position: %ld\n", ftell(fp));

			fclose(fp);
			break;
		}
		else if (res != sizeof(struct person)) {
			perror("partial read");
			goto err;
		}

		printf("name: %s, age: %d\n", p.name, p.age);
	} while (1);

	close(fd);

	return 0;

err:
	if (fd > 0) {
		close(fd);
	}

	return -1;
}

int main(int argc, char **argv)
{
	struct person persons[] = {
		{ "kim", 40 },
		{ "mike", 23 }
	};

	write_info(&persons[0]);
	write_info(&persons[1]);

	dump_info();

	return 0;
}
