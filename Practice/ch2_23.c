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
		printf("등록된 주소록이 없습니다.\n\n");
	else {
		printf("\n이름\t전화번호\t주소\t생일\n");
		printf("----------------------------------------------\n");

		for(i=0;i<length;i++) {
			printf(" %s\t %s\t %s\t %s \n", dir[i].name, dir[i].phone, dir[i].address, dir[i].birthday);
		}
	}
}

void add(void) {
	length++;
	printf("추가할이름 : "); scanf("%s", dir[length - 1].name);
	printf("추가할전화번호 : "); scanf("%s", dir[length - 1].phone);
	printf("추가할주소 : "); scanf("%s", dir[length - 1].address);
	printf("추가할생일 : "); scanf("%s", dir[length - 1].birthday);
	printf("------추가완료-------\n\n");
}

void search(void) {
	char name[20];
	int i;

	printf("검색할이름 : "); scanf("%s", name);

	for(i=0;i<length;i++) {
		if(strcmp(name, dir[i].name) == 0) {
			printf(" %s\t %s\t %s\t %s \n",dir[i].name,dir[i].phone,dir[i].address,dir[i].birthday);
		}else if(i == length) {
			printf("%s 의 정보가 없습니다.\n\n", name);
		}
	}
}

void delete(void) {
	char name[20];
	int i,j;

	printf("삭제할 이름 : "); scanf("%s", name);
	for(i=0;i<length;i++) {
		if(strcmp(name, dir[i].name) == 0) {
			for(j=i;j+1<length;i++) {
				strcpy(dir[j].name, dir[j+1].name);
				strcpy(dir[j].phone, dir[j+1].phone);
				strcpy(dir[j].address, dir[j+1].address);
				strcpy(dir[j].birthday, dir[j+1].birthday);
			}
			printf("삭제완료! \n\n");
			length--;
		}else if(i==length)
			printf("%s 의 정보가 없습니다. \n\n", name);
	}
}

void menu(void) {
	char choice;
	do{
		printf("\n\n==========================================================================\n");
		printf("==================================주소목록================================\n\n");
		printf(" 1) 목록보기\t2)추가하기\t3)검색하기\t4)삭제하기\t5)종료하기\n");
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
			printf("\n주소록 프로그램을 종료합니다.\n"); return ;
		default:
			printf("메뉴번호를 다시 확인해주세요!\n");
		}
	}while(choice != '5');
}

int main(void) {
	menu();
}
