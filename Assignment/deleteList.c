/*
 * Singly_Linked_List.c
 *
 *  Created on: 2019. 4. 10.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char name[20];
	int id;
	struct node *link;
} Node;

Node *head;
void print_list();
Node *search_list_by_name(char *name);
Node *search_list_by_id(int id);
void insert(Node *pre, char *name, int id);
void delete(char *name, int id);

int main(void) {
	Node *pre;

	insert(NULL, "전창완", 1000);
	print_list();

	insert(NULL, "윤재석", 2000);
	print_list();

	pre = search_list_by_name("전창완");
	insert(pre, "김대희", 3000);
	print_list();

	pre = search_list_by_id(1000);
	insert(pre, "김동민", 4000);
	print_list();

	printf("Delete\n");
	delete("윤재석", 2000);
	print_list();

	delete("김동민", 4000);
	print_list();

	delete("김대희", 3000);
	print_list();

	delete("전창안", 1000);
	print_list();

	delete("전창완", 1000);
	print_list();

	delete("김대희", 3000);
}
void print_list() {
	Node *p;
	p = head;
	while (p != NULL) {
		printf("(%s, %d) ", p->name, p->id);
		p = p->link;
	}
	printf("\n");
}

Node *search_list_by_name(char *name) {
	Node *p;
	p = head;
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			return p;
			break;
		} else
			p = p->link;
	}
	return NULL;

}

Node *search_list_by_id(int id) {
	Node *p;
	p = head;
	while (p != NULL) {
		if (p->id == id) {
			return p;
			break;
		} else
			p = p->link;
	}
	return NULL;
}

void insert(Node *pre, char *name, int id) {
	Node *new;

	new = (Node*) malloc(sizeof(Node));
	strcpy(new->name, name);
	new->id = id;

	if (head == NULL) {
		head = new;
		new->link = NULL;
	} else if (pre == NULL) {
		new->link = head;
		head = new;
	} else {
		new->link = pre->link;
		pre->link = new;
	}
}
void delete(char *name, int id) {
	Node *pre;
	Node *del;
	del = search_list_by_name(name);

	if (head == NULL) {
		printf("List is empty!!!\n");
		return;
	}
	if ((strcmp(head->name, name) == 0) && head->id == id) {
		del = head;
		head = del->link;
		free(del);
	} else {
		pre = head;
		while (pre->link != NULL) {
			if ((strcmp(pre->link->name, del->name) == 0
					&& pre->link->id == del->id)) {
				pre->link = del->link;
				free(del);
			} else
				pre = pre->link;
		}
	}

}

