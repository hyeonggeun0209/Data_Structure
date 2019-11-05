/*
 * ch2_20.c
 *
 *  Created on: 2019. 3. 24.
 *      Author: JiHyeongGeun
 */

#include<stdio.h>

void change(float *, float *);

int main(void) {

	float a = 5.6;
	float b = 9.4;
	float *ptr1 = &a;
	float *ptr2 = &b;

	printf("현재 a : %f, b : %f\n", *ptr1, *ptr2);

	change(ptr1,ptr2);

	printf("바꾼 후 a : %f, b : %f", *ptr1, *ptr2);

	return 0;
}

void change(float *i,float *j) {
	float x;
	x = *i;
	*i = *j;
	*j = x;
}

