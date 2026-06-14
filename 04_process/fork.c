#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void test_func(void)
{
	printf("test func - %d\n", getpid());
}

int main(int argc, char **argv)
{
	pid_t pid;

	printf("origin: %d\n", getpid());

	pid = fork();

	if (pid == 0) {
		/* child */
		printf("child: %d\n", getpid());
	}
	else if (pid > 0) {
		/* parent */
		printf("parent: %d, child: %d\n", getpid(), pid);
		wait(NULL);
	}

	test_func();

	return 0;
}
