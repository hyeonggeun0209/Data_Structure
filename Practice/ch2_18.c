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
	printf("���ڿ� �ټ� ���� �Է��Ͻÿ�.\n");

	for(i=0;i<N;i++){
		fflush(stdout);
		scanf("%s", a[i]);
	}
	printf("�Է��� ���ڿ��� ������ �����ϴ�.\n");

	for(i=0;i<N;i++) {
		printf("%s\n",a[i]);
	}
}


