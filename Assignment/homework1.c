/*
 * homework1.c
 *
 *  Created on: 2019. 3. 20.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>

int sum(int n);

int main() {
	printf("%d\n", sum(1000));
}

int sum(int n) {
	if(n==1) {
		return 1;
	}else
		return n + sum(n-1);
}

