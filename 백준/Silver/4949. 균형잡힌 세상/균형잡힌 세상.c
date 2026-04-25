#include <stdio.h>
#include <string.h>

int top = -1;
char stack[101];

// 가장 위 원소 삭제
void pop() {
	if (top >= 0) {
		stack[top--] = 0;
	}
}

// 원소 삽입
void push(int data) {
	stack[++top] = data;
}

int main() {
	char str[101];
	while(1) {
		top = -1;
		gets(str);
		//scanf("%[^\n]s", str);
		if (str[0] == '.') break;
		int boolen = 1;
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] == '[') {
				push('[');
			}
			else if (str[i] == '(') {
				push('(');
			}
			else if (str[i] == ']') {
				push(']');
			}
			else if (str[i] == ')') {
				push(')');
			}
			while (stack[top] == ')' || stack[top] == ']') {
				if (stack[top - 1] == '(' && stack[top] == ')') {
					pop();
					pop();
				}
				else if (stack[top - 1] == '[' && stack[top] == ']') {
					pop();
					pop();
				}
				else {
					break;
				}
			}
		}
		if (top >= 0) boolen = 0;
		if (boolen == 1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}