#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

typedef struct Node {
	char value[21];
	int number;
	struct Node* next;
}Node;

typedef struct HashTable {
	Node* head;
}HashTable;

typedef struct List {
	char str[21];
}List;

int hash(char* str, int n) {
	int i;
	int h = 0;
	for (i = 1; i <= strlen(str); i++) {
		h += str[i] * i;
		h %= n;
	}
	return h;
}

void insert(HashTable* select, char* str, int number) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));

	strcpy(newNode->value, str);
	newNode->next = NULL;
	newNode->number = number;
	if (select->head == NULL) {
		select->head = newNode;
	}
	else {
		Node* node;
		node = select->head;
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newNode;
	}

}

void find(HashTable* table, List* list, char* str, int n) {
	int num;
	if (str[0] < 65) {
		num = atoi(str)-1;
		printf("%s\n", list[num].str);
	}
	else {
		int h = hash(str, n);
		Node* selected = table[h].head;
		while (strcmp(selected->value, str) != 0)
			selected = selected->next;
		printf("%d\n", selected->number+1);
	}
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
	list = (List*)malloc(sizeof(List) * n);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		int h = hash(str, n);
		insert(&hashTable[h], str, i);
		strcpy(list[i].str, str);
	}
	for (i = 0; i < m; i++) {
		scanf("%s", str);
		find(hashTable, list, str, n);
	}

	free(hashTable);
	free(list);
	return 0;
}