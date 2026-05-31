#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
	char name[20];
	int age;
};

static int write_to_file(void)
{
	FILE *fp;
	struct person kim = {
		.name = "kim",
		.age = 20
	};
	struct person lee = {
		.name = "lee",
		.age = 30
	};

	if (!(fp = fopen("person.txt", "w"))) {
		perror("fopen");
		return -1;
	}

	if (fwrite(&kim, sizeof(struct person), 1, fp) != 1) {
		perror("fwrite");
		goto ERR;
	}
	if (fwrite(&lee, sizeof(struct person), 1, fp) != 1) {
		perror("fwrite");
		goto ERR;
	}

	fclose(fp);

	return 0;

ERR:
	if (fp) {
		fclose(fp);
	}

	return -1;
}

static int read_from_file(void)
{
	FILE *fp;
	int i;
	struct person persons[2]; 

	if (!(fp = fopen("person.txt", "r"))) {
		perror("fopen");
		goto ERR;
	}

	if (fread(persons, sizeof(struct person), 2, fp) != 2) {
		perror("fread");
		goto ERR;
	}

	fclose(fp);

	for (i = 0; i < 2; i++) {
		printf("name: %s, age: %d\n",
				persons[i].name,
				persons[i].age);
	}

	return 0;

ERR:
	if (fp) {
		fclose(fp);
	}

	return -1;
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
