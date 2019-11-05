/*
 * homework2.c
 *
 *  Created on: 2019. 3. 20.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>

void star(int n);

int main() {
	int n;
	printf("Enter the number of stars: ");
	fflush(stdout);
	scanf("%d", &n);

	star(n);
}

void star(int n) {
	if(n <= 0) {
		return;
	}else {
		star(n-1);
		for(int i=0;i<n;i++){
			printf("*");
		}
		printf("\n");
	}
}

