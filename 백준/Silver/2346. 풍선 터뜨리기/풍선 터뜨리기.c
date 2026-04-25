#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1 2 9 3 6 5 7 8 10 4
#pragma pack(push, 1)
typedef struct _Node {
	short v;
	short idx;
	struct _Node* next;
	struct _Node* prev;
}Node;

typedef struct _Deque {
	Node* tail;
	Node* head;
	int count;
}Deque;

void push(Deque* deq, short val, short i) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->v = val;
	newNode->idx = i;
	if (deq->count == 0) {
		deq->head = newNode;
		deq->tail = newNode;
		deq->head->prev = deq->tail;
		deq->head->next = deq->tail;
		deq->tail->next = deq->head;
		deq->tail->prev = deq->head;
	}
	else if (deq->count == 1) {
		newNode->prev = deq->head;
		newNode->next = deq->head;
		deq->head->next = newNode;
		deq->tail = newNode;
	}
	else {
		newNode->prev = deq->tail;
		newNode->next = deq->head;
		deq->tail->next = newNode;
		deq->head->prev = newNode;
		deq->tail = newNode;
	}
	deq->count++;
}

void pop(Deque* deq, Node* select, int b) {
	short i;
	Node* ret = select;

	//if (deq->count == 0) return;
	ret->prev->next = ret->next;
	ret->next->prev = ret->prev;
	for (i = b; i < abs(ret->v); i++) {
		if (ret->v < 0) {
			select = select->prev;
			if (ret->idx == select->idx)
				select = select->prev;
		}
		else {
			select = select->next;
			if (ret->idx == select->idx)
				select = select->next;
		}
	}

	/*ret->prev->next = ret->next;
	ret->next->prev = ret->prev;*/
	printf("%d ", ret->idx + 1);
	if (deq->count == 1) return;
	deq->count--;

	pop(deq, select, 0);
	free(ret);
}

int main() {
	short n, i, idx;
	Deque deque = { NULL, NULL, 0 };

	scanf("%hd", &n);
	for (i = 0; i < n; i++) {
		scanf("%hd", &idx);
		push(&deque, idx, i);
	}

	pop(&deque, deque.head, 0);

	return 0;
}