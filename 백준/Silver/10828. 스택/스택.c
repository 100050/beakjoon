#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10000];
int top = -1;

// 가장 위 원소 삭제
void pop() {
	if (top >= 0) {
		printf("%d\n", stack[top]);
		stack[top--] = 0;
	}
	else
		printf("-1\n");
}

// 원소 삽입
void push(int data) {
	stack[++top] = data;
}


// 가장 위의 원소
void isTop() {
	if (top == -1)
		printf("-1\n");
	else
		printf("%d\n", stack[top]);
}

// 스택이 비었는가
void isEmpty() {
	if (top == -1)
		printf("1\n");
	else
		printf("0\n");
}

// 원소 갯수
void isSize() {
	printf("%d\n", top + 1);
}

int main() {
	char answer[11];
	int data;
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", answer);
		if (strcmp(answer, "push") == 0) {
			scanf("%d", &data);
			push(data);
		}
		else if (strcmp(answer, "top") == 0) {
			isTop();
		}
		else if (strcmp(answer, "pop") == 0) {
			pop();
		}
		else if (strcmp(answer, "size") == 0) {
			isSize();
		}
		else if (strcmp(answer, "empty") == 0) {
			isEmpty();
		}
	}

	return 0;
}