/*
 * ch2_22.c
 *
 *  Created on: 2019. 3. 24.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#define N 100

void reverse(char [], char []);

int main(void) {

	char a[N], b[N];
	printf("���ڿ��� �Է��ϼ���: ");
	fflush(stdout);
	scanf("%s", a);
	reverse(a,b);
	printf("�������� ����� �� : ");
	printf("%s", a);

}

void reverse(char a[], char b[]) {
	int i,j,k;

	for(i=0;a[i] != '\0';i++) {
		b[i] = a[i];
	}
	b[i] = a[i];
	k=i--;
	for(j=0;0<=i;j++,i--) {
		a[j] = b[i];
	}
	a[k] = '\0';
}


