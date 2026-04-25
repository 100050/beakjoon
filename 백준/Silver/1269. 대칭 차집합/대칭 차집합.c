#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 451

int num = 0;
int hashTable[MAX][500] = { 0, };

int hash(int a) {
	a %= MAX;

	return  a;
}

void insert(int e) {
	int h = hash(e);
	int i = 0;
	while (hashTable[h][i] != 0)
		i++;
	hashTable[h][i] = e;
}

int find(int e) {
	int h = hash(e);
	int i = 0;

	while (hashTable[h][i] != e && hashTable[h][i] != 0)
		i++;

	if (hashTable[h][i] == e) {
		return 1;
	}

	return 0;
}

int main() {
	int n, m, i, element;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &element);
		insert(element);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &element);
		num += find(element);
	}

	printf("%d", n+m-2*num);

	return 0;
}