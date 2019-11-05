/*
 * ch2_19.c
 *
 *  Created on: 2019. 3. 23.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>

int main(void) {

	char a[100];
	char b[100];

	int i;
	printf("첫 번째 문자열을 입력해주세요 :");
	fflush(stdout);
	scanf("%s", a);

	printf("두 번째 문자열을 입력해주세요 :");
	fflush(stdout);
	scanf("%s", b);

	i = 0;
	while(a[i] == b[i]) {
		if((a[i] == '\0') || (b[i] == '\0')) {
			printf("두 문자열이 같습니다.");
			break;
		}else
			i++;
	}
	if(a[i] != b[i]) {
	printf("두 문자열이 다릅니다.");
	}
}

