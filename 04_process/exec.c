#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void test_func(void)
{
	printf("[exec] test func - %d\n", getpid());
}

int main(int argc, char **argv)
{
	pid_t pid;

	printf("[exec] origin: %d\n", getpid());

	pid = fork();

	if (pid == 0) {
		/* child */
		printf("[exec] child: %d\n", getpid());
		execl("fork", "fork", NULL);
		perror("execl");
		return -1;
	}
	else if (pid > 0) {
		/* parent */
		printf("[exec] parent: %d, child: %d\n", getpid(), pid);
		wait(NULL);
	}

	test_func();

	return 0;
}
