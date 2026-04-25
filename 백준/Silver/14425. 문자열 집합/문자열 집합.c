#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char str[501];
	struct Node* next;
}Node;

typedef struct Bucket {
	Node* head;
}HashTable;

int hashf(char str[]) {
	int hash = 0;
	for (int i = 0; i < strlen(str); i++) {
		hash += str[i] * (i + 1);
	}
	hash %= 10000;
	return hash;
}

void insertNode(HashTable* h, char str[]) {
	int hash = hashf(str);
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->str, str);
	node->next = NULL;
	if (h[hash].head == NULL) {
		h[hash].head = node;
	}
	else {
		Node* select = (Node*)malloc(sizeof(Node));
        select = h[hash].head;
		while (select->next != NULL) {
			select = select->next;
		}
		select->next = node;
	}
}

int research(Node* node, char str[]) {
	if (node == NULL) return 0;

	while (node->next != NULL) {
		if (!strcmp(node->str, str)) {
			return 1;
		}
		node = node->next;
	}
	if (!strcmp(node->str, str)) {
		return 1;
	}

	return 0;
}

int main() {
	HashTable* h;
	h = (HashTable*)malloc(sizeof(HashTable) * 10000);
	char str[501];
	int n, m, i, t;
	for (i = 0; i < 10000; i++) {
		h[i].head = (Node*)malloc(sizeof(Node));
		h[i].head = NULL;
	}
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		insertNode(h, str);
	}
	t = 0;
	for (i = 0; i < m; i++) {
		scanf("%s", str);
		int hash = hashf(str);
		if (research(h[hash].head, str))
			t++;
	}
	printf("%d", t);
}