#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int back, fr, si;
int* queue;
fr = -1;
back = -1;
si = 0;
void push(int data) {
	if (fr == -1)
		fr++;
	queue[++back] = data;
	si++;
}
void pop() {
	if (si == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", queue[fr++]);
		si--;
	}
}
void size2() {
	printf("%d\n", si);
}
void empty() {
	if (si == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}
void front2() {
	if (si == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", queue[fr]);
	}
}
void back2() {
	if (si == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", queue[back]);
	}
}
int main() {
	int n, i, d;
	char command[6];
	scanf("%d", &n);
	queue = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &d);
			push(d);
		}
		else if (strcmp(command, "pop") == 0) {
			pop();
		}
		else if (strcmp(command, "empty") == 0) {
			empty();
		}
		else if (strcmp(command, "size") == 0) {
			size2();
		}
		else if (strcmp(command, "front") == 0) {
			front2();
		}
		else if (strcmp(command, "back") == 0) {
			back2();
		}
	}
	free(queue);
	return 0;
}