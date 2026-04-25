#include <stdio.h>
#include <stdlib.h>
#define INF 2147483646

typedef struct Graph {
	int from;
	int to;
	int val;
} g;

int compare(const int* a, const int* b) {
	return (*a - *b);
}

g heap[100001];
int count;

void swap(g* a, g* b) {
	g temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void hpush(g* node) {
	heap[++count] = *node;
	int i = count;
	while (i > 1 && heap[i].val < heap[i / 2].val) {
		swap(&heap[i], &heap[i / 2]);
		i /= 2;
	}
}

g hpop() {
	g ret;
	ret = heap[1];

	swap(&heap[1], &heap[count]);
	count--;

	int i = 2;
	if (i + 1 <= count) {
		i = (heap[i].val < heap[i + 1].val) ? i : i + 1;
	}
	while (i <=count && heap[i].val < heap[i / 2].val) {
		swap(&heap[i], &heap[i / 2]);
		i *= 2;

		if (i + 1 <= count) {
			i = (heap[i].val < heap[i + 1].val) ? i : i + 1;
		}
	}

	return ret;
}

int v, e;
int selected[10001];
int cnt[10001];
int ans;

void prim(g* graph) {
	int j;
	g node;
	node.from = 1;
	node.to = 1;
	node.val = 0;

	hpush(&node);
	while (count) {
		node = hpop();
		if (selected[node.to] == 0) {
			for (j = cnt[node.to - 1]; j <= cnt[node.to] - 1; j++) {
                if (selected[graph[j].to] == 0)
				    hpush(&graph[j]);
			}
			selected[node.to] = 1;
			ans += node.val;
		}
	}
}

int main() {
	int i;
	int a, b, c;

	scanf("%d %d", &v, &e);
	g* graph = (g*)malloc(sizeof(g) * (e * 2));
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[i].from = a; 
		graph[i].to = b;
		graph[i].val = c;
		graph[i + e].from = b;
		graph[i + e].to = a;
		graph[i + e].val = c;
		cnt[a]++;
		cnt[b]++;
	}
	for (i = 1; i <= v; i++) {
		cnt[i] += cnt[i - 1];
	}

	qsort(graph, e*2, sizeof(g), compare);
	prim(graph);
	
	printf("%d", ans);

	free(graph);
	return 0;
}