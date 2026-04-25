#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char str[11];
	int n;
} Voca;

typedef struct _Node {
	struct _Node* tail;
	Voca* name;
} Node;

typedef struct _HashTable {
	Node* node;
} HashTable;

int x = 1, n, m;

int hash(char* str) {
	int l = strlen(str);
	int h = 0;
	for (int i = 0; i < l; i++) {
		h += (str[i] * (i + 1)) % n;
	}

	return h % n;
}

void push(HashTable* ht, Voca* str) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->name = str;
	int h = hash(str->str);
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
	if (strcmp(ht[h].node->name->str, str) == 0) {
		ht[h].node->name->n++;
		return 0;
	}
	else {
		selectNode = ht[h].node;

		while (strcmp(selectNode->name->str, str) != 0) {
			if (selectNode->tail == NULL) {
				break;
			}
			//printf("%d\n", x);
			selectNode = selectNode->tail;
		}
		if (strcmp(selectNode->name->str, str) == 0) {
			selectNode->name->n++;
			return 0;
		}
	}

	return 1;
}

int compare(const void* a, const void* b) {
	Voca* aa = (Voca*)a;
	Voca* bb = (Voca*)b;
	if (aa->n > bb->n) {
		return -1;
	}
	else if (aa->n < bb->n) {
		return 1;
	}
	else {
		if (strlen(aa->str) > strlen(bb->str)) {
			return -1;
		}
		else if (strlen(aa->str) < strlen(bb->str)) {
			return 1;
		}
		else {
			return strcmp(aa->str, bb->str);
		}

	}
}

int main() {
	int i;
	Voca* str;
	char s[11];
	HashTable* hashTable;

	scanf("%d %d", &n, &m);
	hashTable = (HashTable*)malloc(sizeof(HashTable) * n);
	str = (Voca*)malloc(sizeof(Voca) * n);
	for (int j = 0; j < n; j++) {
		hashTable[j].node = NULL;
		strcpy(str[j].str, "");
	}
	int k = 0;
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		if (strlen(s) >= m) {
			if (find(hashTable, s)) {
				strcpy(str[k].str, s);
				str[k].n = 1;
				push(hashTable, &str[k]);
				k++;
			}
		}
	}
	qsort(str, k, sizeof(Voca), compare);

	for (i = 0; i < k; i++) {
		printf("%s\n", str[i].str);
	}

	free(str);
	free(hashTable);
	return 0;
}