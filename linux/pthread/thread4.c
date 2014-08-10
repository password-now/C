#include<stdio.h>
#include<pthread.h>

/* 线程要执行的函数 */
void *run(void *args) {
	printf("running start\n");
	int i;
	for(i = 0; i < 100; i++) {
		printf("running...\n");
	}
	printf("running end\n");
	return NULL;
}

int main() {
	pthread_t threadId;
	int rc = pthread_create(&threadId, NULL, run, NULL);
	if(0 != rc) {
		printf("create thread fial!\n");
		return -1;
	}
	printf("create thread success\n");

	/* 等待另一个线程结束 */
	pthread_join(threadId, 0);

	return 0;
}