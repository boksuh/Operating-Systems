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
	srand(time(NULL));
  FILE *fp = fopen("result.dat", "w");

	pid_t pid;

	for (int i=0; i<4; i++) {
		pid = fork();
		
		if (pid == 0) {
			for (int i=0; i<10000; i++) {
				number[rand()%100]++;
			}

			for (int i=0; i<100; i++) {
				sum += number[i];
				fputs("good ", fp);
			}

			fputs("sum \n", fp);
			printf("End of child process\n");
		}

		else if (pid > 0) {
			printf("Parent status\n");
			wait(NULL);
		}
		else {
			printf("Fork error\n");
			exit(0);
		}
		
	}






	fclose(fp);
	// 0~100 rand()%100
	
	
	
	return 0;
}