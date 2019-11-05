/*
 * ch2_21.c
 *
 *  Created on: 2019. 3. 24.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>

int main(void) {
	int i;
	char a[100];
	printf("문자열을 입력하세요:");
	fflush(stdout);
	scanf("%s", a);
	printf("\n");

	char *p = a;

	for(i=0;*(p + i) != '\0';i++) {
		if((65 <= *(p+i)) && (*(p+i) <= 90)) {
			*(p+i) += 32;
		}else if((97 <= *(p+i)) && (*(p+i) <= 122)) {
			*(p+i) -= 32;
		}
	}
	printf("대문자 -> 소문자, 소문자 -> 대문자 변환\n");
	printf("%s", a);
}


