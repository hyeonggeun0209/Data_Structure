/*
 * Project2.c
 *
 *  Created on: 2019. 5. 6.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct name_card {
	char name[20];
	int id;
	struct name_card* link;
} Namecard;

Namecard *head;

Namecard *make_Namecard(char name[], int id) {
	Namecard *newCard = (Namecard *) malloc(sizeof(Namecard));

	strcpy(newCard->name, name);
	newCard->id = id;
	newCard->link = NULL;

	return newCard;
}

void init(void) {
	head = NULL;
}

int size(void) {
	int length = 0;
	Namecard *p = head;
	while (p != NULL) {
		length++;
		p = p->link;
	}

	return length;
}

int is_empty(void) {
	if (size() == 0)
		return 1;
	else
		return 0;
}

Namecard *get_entry(int pos) {
	Namecard *p = head;
	int num = 0;

	if (pos == 0)
		return head;
	else {
		while (num != pos) {
			num++;
			p = p->link;
		}
	}
	return p;
}

void replace(int pos, Namecard *item) {
	Namecard *p = head;
	int num = 0;
	if (size() < pos)
		printf("위치 오류\n");
	else {
		while (num != pos) {
			num++;
			p = p->link;
		}
		p->id = item->id;
		strcpy(p->name, item->name);
	}
}

void insert(int pos, Namecard *item) {
	Namecard *p = head;
	int num = 0;
	if (size() < pos)
		printf("위치 오류\n");
	else if (is_empty()) {
		head = item;
	} else if (pos == 0) {
		item->link = head;
		head = item;
	} else {
		while (num != pos - 1) {
			num++;
			p = p->link;
		}
		item->link = p->link;
		p->link = item;
	}
}

void delete(int pos) {
	Namecard *p = head;
	Namecard *q;
	int num = 0;
	if (size() < pos)
		printf("위치 오류\n");
	else if (pos == 0) {
		head = p->link;
		free(p);
	} else {
		while (num != pos - 1) {
			num++;
			p = p->link;
		}
		q = p->link;
		p->link = q->link;
		free(q);
	}
}

int find(Namecard *item) {
	Namecard *p = head;
	int num = 0;
	while (p != NULL) {
		if ((p->id == item->id) && (strcmp(p->name, item->name) == 0))
			return num;
		num++;
		p = p->link;
	}
	return -1;
}

void print_list(char *msg) {
	Namecard *p = head;
	printf("%s: ", msg);
	while (p != NULL) {
		printf("(%s, %d) ", p->name, p->id);
		p = p->link;
	}
	printf("\n\n");
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
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");


	printf("%s is found at %d\n", "장경호", find(make_Namecard("장경호", 20181520)));
	printf("%s is found at %d\n", "서영훈", find(make_Namecard("서영훈", 20181499)));

}

