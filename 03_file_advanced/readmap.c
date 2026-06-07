#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

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
	struct stat sb;
	struct person *p;
	int i;

	fd = open("person_info", O_RDONLY);

	if (fd == -1) {
		perror("open");
		return -1;
	}

	if (fstat(fd, &sb) == -1) {
		perror("fstat");
		close(fd);
		return -1;
	}
	
	p = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	
	if (p == MAP_FAILED) {
		perror("mmap");
		close(fd);
		return -1;
	}

	for (i = 0; i < sb.st_size / sizeof(struct person); i++) {
		printf("name: %s, age: %d\n", p[i].name, p[i].age);
	}	

	close(fd);

	return 0;
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
