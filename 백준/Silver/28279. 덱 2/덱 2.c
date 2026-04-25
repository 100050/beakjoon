#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LM 1000002

typedef struct _node {
	int v;
	struct _node* prev;
	struct _node* next;
}_node;
_node* NODE;
int idx, size;
int n, o, x;
_node* head, * tail, * node;

int main() {
	scanf("%d", &n);
	NODE = (_node*)malloc(sizeof(_node) * n);
	head = &NODE[idx++];
	tail = &NODE[idx++];
	head->next = tail;
	tail->prev = head;

	while (n--) {
		scanf("%d", &o);
		switch (o) {
		case 1:
			scanf("%d", &x);
			node = &NODE[idx++];
			node->v = x;
			node->next = head->next;
			node->prev = head;
			node->next->prev = node;
			head->next = node;
			++size;
			break;
		case 2:
			scanf("%d", &x);
			node = &NODE[idx++];
			node->v = x;
			node->next = tail;
			node->prev = tail->prev;
			tail->prev->next = node;
			tail->prev = node;
			++size;
			break;
		case 3:
			if (size == 0) printf("-1\n");
			else {
				printf("%d\n", head->next->v);
				head->next->next->prev = head;
				head->next = head->next->next;
				--size;
			}
			break;
		case 4:
			if (size == 0) printf("-1\n");
			else {
				printf("%d\n", tail->prev->v);
				tail->prev->prev->next = tail;
				tail->prev = tail->prev->prev;
				--size;
			}
			break;
		case 5:
			printf("%d\n", size);
			break;
		case 6:
			printf("%d\n", size == 0);
			break;
		case 7:
			if (size == 0) printf("-1\n");
			else printf("%d\n", head->next->v);
			break;
		case 8:
			if (size == 0) printf("-1\n");
			else printf("%d\n", tail->prev->v);
			break;
		}
	}

	free(NODE);
	return 0;
}