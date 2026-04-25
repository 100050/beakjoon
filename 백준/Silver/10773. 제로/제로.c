#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long stack[100000];
long long top = -1;

// 가장 위 원소 삭제
void pop() {
	stack[top--] = 0;
}

// 원소 삽입
void push(int data) {
	stack[++top] = data;
}

int main() {
	long long answer, total;
	long long n, i;
	scanf("%lld", &n);
	i = 0;
	while (i++ < n) {
		scanf("%lld", &answer);
		if (answer == 0) {
			pop();
		}
		else {
			push(answer);
		}
	}
	total = 0;
	for (i = 0; i < n; i++) {
		total += stack[i];
	}
	printf("%lld", total);

	return 0;
}