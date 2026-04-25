#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

typedef struct Node {
	char value[21];
	struct Node* prev;
}Node;

typedef struct HashTable {
	Node* head;
}HashTable;

typedef struct List {
	char str[21];
}List;

int compare(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}


unsigned int hash(char* str, int n) {
	unsigned int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % n;
}

void insert(HashTable* select, char* str) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));

	strcpy(newNode->value, str);
	newNode->prev = NULL;
	if (select->head == NULL) {
		select->head = newNode;
	}
	else {
		Node* node;
		node = select->head;
		newNode->prev = node;
		select->head = newNode;
	}

}

int find(HashTable* table, List* list, char* str, int n) {
	int h = hash(str, n);
	if (table[h].head == NULL)
		return 0;
	Node* selected = table[h].head;
	while (strcmp(selected->value, str) != 0) {
		if (selected->prev == NULL)
			break;
		selected = selected->prev;
	}

	if (strcmp(selected->value, str) != 0) {
		return 0;
	}

	strcpy(list->str, selected->value);

	return 1;
}

int main() {
	int n, m;
	int i;
	char str[21];
	HashTable* hashTable;
	List* list;

	scanf("%d %d", &n, &m);
	hashTable = (HashTable*)malloc(sizeof(HashTable) * n);
	for (i = 0; i < n; i++) {
		hashTable[i].head = NULL;
	}
	int min;
	if (n > m)
		min = m;
	else
		min = n;
	list = (List*)malloc(sizeof(List) * min);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		int h = hash(str, n);
		insert(&hashTable[h], str);
	}
	int l = 0;
	for (i = 0; i < m; i++) {
		scanf("%s", str);
		l += find(hashTable, &list[l], str, n);
	}

	printf("%d\n", l);
	qsort(list, l, sizeof(List), compare);
	for (i = 0; i < l; i++) {
		printf("%s\n", list[i].str);
	}

	free(hashTable);
	free(list);
	return 0;
}