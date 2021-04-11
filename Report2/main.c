#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int number[100] = { 0, };
int t_iter[10] = { 0, };
int t_sum = 0;

void *newThread(void *count) {
	int *pcount = (int *)count;
	for (int i=0; i<100000; i++) {
		number[rand()%100]++;
		(*pcount)++;
	}
	pthread_exit(0);
}

int main(void) {
  FILE *fp = fopen("result.dat", "w");
	srand(time(NULL));
	pthread_t tid[10];
	int sum = 0;
	
	for (int i=0; i<10; i++) {
		if (pthread_create(&tid[i], NULL, newThread, &t_iter[i]) < 0) {
			exit(0);
		}
	}

	for (int i=0; i<10; i++) {
		pthread_join(tid[i], NULL);
	}

	for (int i=0; i<100; i++) {
		sum += number[i];
	}

	for (int i=0; i<10; i++) {
		t_sum += t_iter[i];
	}

	fprintf(fp, "number[100] : ");

	for (int i=0; i<100; i++) {
		fprintf(fp, "%d ", number[i]);
	}

	fprintf(fp, "\n\nsum = %d\n\nt_iter[10] : ", sum);

	for (int i=0; i<10; i++) {
		fprintf(fp, "%d ", t_iter[i]);
	}

	fprintf(fp, "\n\nt_sum = %d\n", t_sum);

	fclose(fp);

	return 0;
}
