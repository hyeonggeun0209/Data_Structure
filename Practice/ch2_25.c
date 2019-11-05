/*
 * ch2_25.c
 *
 *  Created on: 2019. 3. 24.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>

int fibonacci(int);

int main(void) {

	int i, n;

	printf("n : ");
	fflush(stdout);
	scanf("%d", &n);

	for(i=0;i<n;i++) {
		printf("%d ", fibonacci(i));
	}

	return 0;
}

int fibonacci(int n) {
	if(n==0 || n==1) {
		return n;
	}else
		return fibonacci(n-1) + fibonacci(n-2);
}


