#include <stdio.h>
#include <stdlib.h>

int top = -1, idx = 1, idx2 = 0, num, b = 1;
int stack[200000];
char arr[200000];

// 가장 위 원소 삭제
void pop() {
	if (top >= 0) {
		if (num != stack[top]) {
			printf("NO");
			b = 0;
			return 0;
		}
		arr[idx2++] = '-';
		stack[top--] = 0;
	}
}

// 원소 삽입
void push(int data) {
	arr[idx2++] = '+';
	stack[++top] = data;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		while (idx <= num) {
			push(idx);
			idx++;
		}
		pop();
		if (b == 0) {
			return 0;
		}
	}
	for (int i = 0; i < idx2; i++) {
		printf("%c\n", arr[i]);
	}

    return 0;
}