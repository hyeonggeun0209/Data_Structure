/*
 * ch2_18.c
 *
 *  Created on: 2019. 3. 23.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#define N 5
int main(void) {

	char a[N][100];
	int i;
	printf("문자열 다섯 개를 입력하시오.\n");

	for(i=0;i<N;i++){
		fflush(stdout);
		scanf("%s", a[i]);
	}
	printf("입력한 문자열은 다음과 같습니다.\n");

	for(i=0;i<N;i++) {
		printf("%s\n",a[i]);
	}
}


