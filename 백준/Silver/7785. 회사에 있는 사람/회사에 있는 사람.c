#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct List* value;
	struct Node* prev;
}Node;

typedef struct HashTable {
	Node* head;
}HashTable;

typedef struct List {
	char str[6];
}List;

int compare(const void* a, const void* b) {
	return -strcmp((char*)a, (char*)b);
}

int hash(char* s, int n)
{
	int a = 0;
	while (*s) // 이진법을 통한 해시함수
		a = (a ^ *s++ ) * 2166136261 % n;
	return a % n;
}

void insert(HashTable* select, List* list, char* str) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));

	newNode->value = list;
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

//int find(HashTable* table, List* list, char* str, int n) {
//	int h = hash(str, n);
//	if (table[h].head == NULL)
//		return 0;
//	Node* selected = table[h].head;
//	while (strcmp(selected->value, str) != 0) {
//		if (selected->prev == NULL)
//			break;
//		selected = selected->prev;
//	}
//
//	if (strcmp(selected->value, str) != 0) {
//		return 0;
//	}
//
//	strcpy(list->str, selected->value);
//
//	return 1;
//}

void del(HashTable* table, List* list, char* str) {
	Node* select = table->head;
	if (strcmp(select->value->str, str) == 0) {
		if (select->prev == NULL) {
			table->head = NULL;

		}
		else {
			table->head = select->prev;
		}
		List* s = select->value;
		strcpy(s->str, "1");

		return;
	}
	while (strcmp(select->prev->value->str, str) != 0) {
		select = select->prev;
	}
	List* s = select->prev->value;
	strcpy(s->str, "1");

	if (select->prev->prev == NULL) {
		select->prev = NULL;
	}
	else {
		select->prev = select->prev->prev;
	}
}

int main() {
	int n;
	int i, l;
	char str[21];
	HashTable* hashTable;
	List* list;
	char a[6];

	scanf("%d", &n);
	hashTable = (HashTable*)malloc(sizeof(HashTable) * n);
	list = (List*)malloc(sizeof(List) * n);
	for (i = 0; i < n; i++) {
		strcpy(list[i].str, "1");
		hashTable[i].head = NULL;
	}
	l = 0;
	for (i = 0; i < n; i++) {
		scanf("%s %s", str, a);
		if (strcmp(a, "enter") == 0) {
			int h = hash(str, n);
			strcpy(list[i].str, str);
			insert(&hashTable[h], &list[i], str);
			l++;
		}
		else {
			int h = hash(str, n);
			del(&hashTable[h], list, str);
			l--;
		}
	}

	qsort(list, n, sizeof(List), compare);
	for (i = 0; i < l; i++) {
		printf("%s\n", list[i].str);
	}

	free(hashTable);
	free(list);
	return 0;
}