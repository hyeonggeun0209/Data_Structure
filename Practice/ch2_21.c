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
	printf("���ڿ��� �Է��ϼ���:");
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
	printf("�빮�� -> �ҹ���, �ҹ��� -> �빮�� ��ȯ\n");
	printf("%s", a);
}


