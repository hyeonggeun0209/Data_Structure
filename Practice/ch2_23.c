/*
 * ch2_23.c
 *
 *  Created on: 2019. 3. 24.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#include <string.h>

struct {
	char name[20];
	char phone[15];
	char address[300];
	char birthday[8];
} dir[50];

int length = 0;

void list(void) {
	int i;
	if(length == 0)
		printf("��ϵ� �ּҷ��� �����ϴ�.\n\n");
	else {
		printf("\n�̸�\t��ȭ��ȣ\t�ּ�\t����\n");
		printf("----------------------------------------------\n");

		for(i=0;i<length;i++) {
			printf(" %s\t %s\t %s\t %s \n", dir[i].name, dir[i].phone, dir[i].address, dir[i].birthday);
		}
	}
}

void add(void) {
	length++;
	printf("�߰����̸� : "); scanf("%s", dir[length - 1].name);
	printf("�߰�����ȭ��ȣ : "); scanf("%s", dir[length - 1].phone);
	printf("�߰����ּ� : "); scanf("%s", dir[length - 1].address);
	printf("�߰��һ��� : "); scanf("%s", dir[length - 1].birthday);
	printf("------�߰��Ϸ�-------\n\n");
}

void search(void) {
	char name[20];
	int i;

	printf("�˻����̸� : "); scanf("%s", name);

	for(i=0;i<length;i++) {
		if(strcmp(name, dir[i].name) == 0) {
			printf(" %s\t %s\t %s\t %s \n",dir[i].name,dir[i].phone,dir[i].address,dir[i].birthday);
		}else if(i == length) {
			printf("%s �� ������ �����ϴ�.\n\n", name);
		}
	}
}

void delete(void) {
	char name[20];
	int i,j;

	printf("������ �̸� : "); scanf("%s", name);
	for(i=0;i<length;i++) {
		if(strcmp(name, dir[i].name) == 0) {
			for(j=i;j+1<length;i++) {
				strcpy(dir[j].name, dir[j+1].name);
				strcpy(dir[j].phone, dir[j+1].phone);
				strcpy(dir[j].address, dir[j+1].address);
				strcpy(dir[j].birthday, dir[j+1].birthday);
			}
			printf("�����Ϸ�! \n\n");
			length--;
		}else if(i==length)
			printf("%s �� ������ �����ϴ�. \n\n", name);
	}
}

void menu(void) {
	char choice;
	do{
		printf("\n\n==========================================================================\n");
		printf("==================================�ּҸ��================================\n\n");
		printf(" 1) ��Ϻ���\t2)�߰��ϱ�\t3)�˻��ϱ�\t4)�����ϱ�\t5)�����ϱ�\n");
		scanf("%c", &choice); getchar();
		switch(choice){
		case '1':
			list(); break;
		case '2':
			add(); getchar(); break;
		case '3':
			search(); getchar(); break;
		case '4':
			delete(); getchar(); break;
		case '5':
			printf("\n�ּҷ� ���α׷��� �����մϴ�.\n"); return ;
		default:
			printf("�޴���ȣ�� �ٽ� Ȯ�����ּ���!\n");
		}
	}while(choice != '5');
}

int main(void) {
	menu();
}
