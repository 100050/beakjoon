#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	struct _Node* tail;
	char name[21];
	int t;
} Node;

typedef struct _HashTable {
	Node* node;
} HashTable;

int x = 1, n, t = -1;

int hash(char* str) {
	int l = strlen(str);
	int h = 0;
	for (int i = 0; i < l; i++) {
		h += (str[i] ^ ((i + 1) << 2)) % n;
	}

	return h % n;
}

void push(HashTable* ht, char* str) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->t = t;
	strcpy(newNode->name, str);
	int h = hash(str);

	if (ht[h].node == NULL) {
		ht[h].node = newNode;
		newNode->tail = NULL;
	}
	else {
		Node* selectNode = ht[h].node;

		newNode->tail = selectNode;
		ht[h].node = newNode;
	}
}

int find(HashTable* ht, char* str) {
	Node* selectNode;

	int h = hash(str);
	if (ht[h].node == NULL)
		return 1;
	if (strcmp(ht[h].node->name, str) == 0 && ht[h].node->t == t) {

		return 0;
	}
	else {
		selectNode = ht[h].node;

		while (strcmp(selectNode->name, str) != 0 || selectNode->t != t) {
			if (selectNode->tail == NULL) {
				break;
			}
			//printf("%d\n", x);
			selectNode = selectNode->tail;
		}
		if (strcmp(selectNode->name, str) == 0 && selectNode->t == t) {

			return 0;
		}
	}

	return 1;
}

int main() {
	int i;
	char str[2][21];
	HashTable* hashTable;

	scanf("%d", &n);
	hashTable = (HashTable*)malloc(sizeof(HashTable) * 2 * n);
	for (int j = 0; j < n; j++) {
		hashTable[j].node = NULL;
	}
	push(hashTable, "ChongChong");
	for (i = 0; i < n; i++) {
		scanf("%s %s", str[1], str[0]);
		if (!find(hashTable, str[0]) && !find(hashTable, str[1]))
			continue;
		if (!find(hashTable, str[0])) {
			x++;
			push(hashTable, str[1]);
		}
		else if (!find(hashTable, str[1])) {
			x++;
			push(hashTable, str[0]);
		}
	}

	printf("%d", x);

	free(hashTable);
	return 0;
}