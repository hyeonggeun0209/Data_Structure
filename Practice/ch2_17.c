/*
 * ch2_17.c
 *
 *  Created on: 2019. 3. 23.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#define N 6
int main(void) {
	int a[N] = {19, 2, 25, 92, 36, 45};
	int i,min,max;
	float avg,sum,sum2,var;
	for(i=0;i<N;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	min = a[0];
	for(i=1;i<N;i++) {
		if(a[i] < min) {
			min = a[i];
		}
	}
	max = a[0];
	for(i=1;i<N;i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}
	printf("min = %d, max = %d", min, max);
	printf("\n");
	sum = 0;
	for(i=0;i<N;i++) {
		sum += a[i];
	}
	avg = sum / N;
	printf("avg = %f", avg);
	printf("\n");

	sum2 = 0;
	for(i=0;i<N;i++) {
		sum2 += (avg-a[i]) * (avg-a[i]);
	}
	var = sum2 / N;
	printf("var = %f", var);


}


