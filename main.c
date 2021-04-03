#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROCESS_NUM 10

int number[100] = {0, };

int main(void) {
	int sum = 0;
	char* string;
  FILE *fp = fopen("result.dat", "w");

	for (int i=0; i<10; i++) {
		if (fork() == 0) {
			srand(time(NULL));
			for(int i=0; i<100000; i++) {
				number[rand()%100]++;
			}
			sprintf(string, "[Pid: %d] --> ", getpid());
			fputs(string, fp);

			for (int i=0; i<100; i++) {
				sprintf(string, "%d ", number[i]);
				fputs(string, fp);
				sum += number[i];
			}

			sprintf(string, "(Sum = %d)\n", sum);
			fputs(string, fp);

			exit(0);
		}
	}

	for (int i=0; i<10; i++) {
		wait(NULL);
	}

	sprintf(string, "Main Process --> ");
	fputs(string, fp);

	for (int i=0; i<100; i++) {
		sprintf(string, "%d ", number[i]);
		fputs(string, fp);
		sum += number[i];
	}

	sprintf(string, "(Sum = %d)\n", sum);
	fputs(string, fp);

	fclose(fp);

	return 0;
}