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
	printf("ù ��° ���ڿ��� �Է����ּ��� :");
	fflush(stdout);
	scanf("%s", a);

	printf("�� ��° ���ڿ��� �Է����ּ��� :");
	fflush(stdout);
	scanf("%s", b);

	i = 0;
	while(a[i] == b[i]) {
		if((a[i] == '\0') || (b[i] == '\0')) {
			printf("�� ���ڿ��� �����ϴ�.");
			break;
		}else
			i++;
	}
	if(a[i] != b[i]) {
	printf("�� ���ڿ��� �ٸ��ϴ�.");
	}
}

