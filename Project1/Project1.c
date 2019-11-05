/*
 * Project1.c
 *
 *  Created on: 2019. 4. 4.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#include <string.h>

#define MAX_IOT_LIST_SIZE 45

int length;

typedef struct {
	char name[20];
	int id;
} Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE];

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}



int is_empty(void) {
	if(length == 0) {
		return 1;
	} else
		return 0;
}

int is_full(void) {
	if(length == MAX_IOT_LIST_SIZE) {
		return 1;
	} else
		return 0;
}

void init(void) {
	length = 0;
}

void insert(int pos, Namecard item) {
	int j = length;
	if((is_full() == 1) || (pos > length)) {
		printf("포화상태 오류 또는 삽입 위치 오류\n");
		return ;
	} else if(length == 0){
		iot_list[pos] = item;
	} else {
		for(int i=pos;i<j;i++) {
			iot_list[j] = iot_list[j-1];
			j--;
		}
	}
	iot_list[pos] = item;
	length++;
}

void delete(int pos) {
	int j = pos;
	if((pos >= length) || (is_empty() == 1)) {
		printf("공백상태 오류 또는 삭제 위치 오류\n");
		return;
	} else {
		for(int i=pos;i<length-1;i++) {
			iot_list[j] = iot_list[j+1];
			j++;
		}
	}
	length--;
}

Namecard get_entry(int pos) {
	return iot_list[pos];
}

int find(Namecard item) {
	for(int i=0;i<length;i++) {
		if((strcmp(iot_list[i].name, item.name) == 0)&& iot_list[i].id == item.id) {
			return i;
			break;
		}
	}
	return -1;
}

void replace(int pos, Namecard item) {
	if(pos >= length) {
		 printf("교체 위치 오류\n");
	} else {
		iot_list[pos] = item;
	}
}

int size(void) {
	return length;
}

void sort_list(void) {
	Namecard temp;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(iot_list[j].id > iot_list[j+1].id)
			{
				temp = iot_list[j];
				iot_list[j] = iot_list[j+1];
				iot_list[j+1] = temp;
			}
		}
	}
}

void print_list(char *msg) {
	if(length == 0) {
		printf("%s:\n\n", msg);
	} else {
		printf("%s:", msg);
		for(int i=0;i<length;i++) {
			printf(" (%s, %d)", iot_list[i].name, iot_list[i].id);
	}
		printf("\n\n");
	}
}
int main(void) {
	init();
	print_list("Init");

	insert(0, make_Namecard("지형근", 20181494)); // 본인 이름, 학번 넣기
	insert(0, make_Namecard("강병훈", 20181503));
	insert(1, make_Namecard("박선균", 20181498));
	insert(size(), make_Namecard("김연주", 20181531));
	insert(3, make_Namecard("이진우", 20181525));
	insert(size(), make_Namecard("강현익", 20181521));
	insert(10, make_Namecard("이병우", 20181502));
	print_list("Insert");

	replace(size() - 1, make_Namecard("김승겸", 20181508));
	replace(4, make_Namecard("장경호", 20181520));
	replace(20, make_Namecard("윤병수", 20181504));
	print_list("Replace");

	delete(3);
	delete(size() -1);
	delete(0);
	delete(30);
	print_list("Delete");

	sort_list();
	print_list("Sort");

	printf("%s is found at %d\n", "장경호", find(make_Namecard("장경호", 20181520)));
	printf("%s is found at %d\n", "서영훈", find(make_Namecard("서영훈", 20181499)));


}


