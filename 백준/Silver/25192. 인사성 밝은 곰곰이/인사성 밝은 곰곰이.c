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

int x = 0, n, t = -1;

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
	char str[21];
	HashTable* hashTable;

	scanf("%d", &n);
	hashTable = (HashTable*)malloc(sizeof(HashTable)*n);
	for (int j = 0; j < n; j++) {
        hashTable[j].node = NULL;
    }
    for (i = 0; i < n; i++) {
		scanf("%s", str);
		if (strcmp(str, "ENTER") == 0) {
			t++;
		}
		else {
			if (find(hashTable, str)) {
				push(hashTable, str);
				x++;
			}
		}
	}

	printf("%d", x);

	free(hashTable);
	return 0;
}