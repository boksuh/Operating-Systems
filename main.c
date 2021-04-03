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








	fclose(fp);
	// 0~100 rand()%100
	
	
	
	return 0;
}