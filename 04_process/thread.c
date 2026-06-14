#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TRY 100000000

static int shared = 0;
pthread_mutex_t mutex;

void *child_thread_main(void *arg)
{
	int i;
	printf("tid: %lu\n", pthread_self());

	pthread_mutex_lock(&mutex);
	for (i = 0; i < MAX_TRY; i++) {
		shared++;
	}

	for (i = 0; i < MAX_TRY; i++) {
		shared--;
	}
	pthread_mutex_unlock(&mutex);

	return NULL;
}

int main(int argc, char **argv)
{
	int ret;
	pthread_t child_threads[2];

	pthread_mutex_init(&mutex, NULL);

	ret = pthread_create(&child_threads[0], NULL, child_thread_main, NULL);
	if (ret) {
		perror("pthread_create");
		return -1;
	}

	ret = pthread_create(&child_threads[1], NULL, child_thread_main, NULL);
	if (ret) {
		perror("pthread_create");
		return -1;
	}

	ret = pthread_join(child_threads[0], (void **)NULL);
	if (ret) {
		perror("pthread_join");
		return -1;
	}

	ret = pthread_join(child_threads[1], (void **)NULL);
	if (ret) {
		perror("pthread_join");
		return -1;
	}

	printf("shared: %d\n", shared);

	pthread_mutex_destroy(&mutex);

	return 0;
}
