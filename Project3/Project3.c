/*
 * Project3.c
 *
 *  Created on: 2019. 5. 8.
 *      Author: JiHyeongGeun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
#define EXPR_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(element item) {
	if (isFull()) {
		printf("\n\n Stack is FULL! \n");
		return;
	} else
		stack[++top] = item;
}

element pop() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty!!\n");
		return 0;
	} else
		return stack[top--];
}

element peek() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty !\n");
		return 0;
	} else
		return stack[top];
}

int testPair(char *exp) {
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = -1;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(symbol);
			break;
		case ')':
		case ']':
		case '}':
			if (top == -1)
				return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')')
						|| (open_pair == '[' && symbol != ']')
						|| (open_pair == '{' && symbol != '}'))
					return 0;
				else
					break;
			}
		}
	}
	if (top == -1)
		return 1;
	else
		return 0;
}

int precedence(char op) {
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;

	}
	return -1;
}

void infix_to_postfix(char input[], char post[]) {
	int i = 0, j = 0;
	char c, op;

	while (input[i] != '\0') {
		c = input[i++];

		if ((c >= '0' && c <= '9')) {
			post[j] = c; j++;
		} else if (c == '(')
			push(c);
		else if (c == ')') {
			while (isEmpty() == 0) {
				op = pop();
				if (op == '(')
					break;
				else {
					post[j++] = ' ';
					post[j++] = op;
				}
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (isEmpty() == 0) {
				op = peek();
				if (precedence(c) <= precedence(op)) {
					post[j++] = ' ';
					post[j++] = op;
					pop();
				} else
					break;
			}
			push(c);
			post[j++] = ' ';
		}
	}
	while (isEmpty() == 0) {
		post[j++] = ' ';
		post[j++] = pop();

	}
	post[j] = '\0';
}

element evalPostfix(char *exp) {
	int opr1, opr2, value;
	int  j, k , i = 0;
	char temp[100];
	int length = strlen(exp);
	char symbol;
	top = -1;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol == ' ') {
			continue;
		}

		k = 0;

		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			for (j = i; exp[j] != ' '; j++) {
				temp[k] = exp[j];
				k++;
				i++;
			}
			temp[k] = '\0';

			value = atoi(temp);

			push(value);
		} else {
			opr2 = pop();
			opr1 = pop();

			switch (symbol) {
			case '+':
				push(opr1 + opr2);
				break;
			case '-':
				push(opr1 - opr2);
				break;
			case '*':
				push(opr1 * opr2);
				break;
			case '/':
				push(opr1 / opr2);
				break;
			}
		}
	}

	return pop();
}

int main(void) {
	int result;
	char input[EXPR_SIZE];
	char postfix[EXPR_SIZE];

	while (1) {
		printf("계산할 수식을 입력하세요: ");
		fflush(stdout);
		scanf("%s", input);

		if (testPair(input) != 1) {
			printf("수식이 잘못되었습니다.\n\n");
			continue;
		}

		infix_to_postfix(input, postfix);
		printf("후위 표기식 : %s\n", postfix);

		result = evalPostfix(postfix);
		printf("연산 결과 => %d\n\n", result);
	}
}

