/*
 * ch2_16.c
 *
 *  Created on: 2019. 3. 23.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#define N 10
#define M 6

int main(void) {
	int num = 1, korean, english, math, total, average, i, j;
	int A[N][M];
	printf("���� ���� ����\n");
	fflush(stdout);
	for(i=0;i<N;i++) {

		scanf("%d %d %d", &korean, &english, &math);
		printf("\n");
		total = korean + english + math;
		average = total / 3;
		A[i][j++] = num++;
		A[i][j++] = korean;
		A[i][j++] = english;
		A[i][j++] = math;
		A[i][j++] = total;
		A[i][j] = average;
		j=0;
	}
	printf("\t�й�\t����\t����\t����\t����\t���\n");
	printf("*******************************************************\n");
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			printf("\t%d", A[i][j]);
		}
		printf("\n");
	}



}







