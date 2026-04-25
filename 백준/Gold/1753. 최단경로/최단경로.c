#include <stdio.h>
#include <stdlib.h>
#define INF 3000001
#define MAX_VERTICES 20001

//노드를 정의할 구조체
typedef struct GraphNode {
	int vertex; //정점
	int val;
	struct GraphNode* link;
}GraphNode;

//노드가 저장되는 리스트를 정의할 구조체
typedef struct GraphType {
	int n; //정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
	GraphNode* adj_list2[MAX_VERTICES];
}GraphType;

//그래프 초기화
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 1; v <= MAX_VERTICES - 1; v++) {
		g->adj_list[v] = NULL;
	}
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입함
void insert_edge(GraphType* g, int u, int v, int w) {
	GraphNode* node;
	//새로운 노드 동적 생성, node에는 시작 메모리 주소가 저장
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->val = w;
	node->link = NULL;
	if (g->adj_list[u] == NULL) {
		g->adj_list[u] = node;
		g->adj_list2[u] = node;
	}
	else {
		g->adj_list2[u]->link = node;
		g->adj_list2[u] = node;
	}
}

void swap(GraphNode* a, GraphNode* b) {
	GraphNode temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

GraphNode heap[300001];
int count = 0;

void hpush(GraphNode x) {
	heap[++count] = x;
	int i = count;

	while (i > 1 && heap[i].val < heap[i / 2].val) {
		swap(&heap[i], &heap[i / 2]);
		i /= 2;
	}
}

GraphNode hpop() {
	GraphNode ret;
	ret = heap[1];

	swap(&heap[1], &heap[count]);
	count--;
	
	int i = 2;
	if (i + 1 <= count && heap[i].val > heap[i + 1].val)
		i++;

	while (i <= count && heap[i / 2].val > heap[i].val) {
		swap(&heap[i], &heap[i / 2]);
		i *= 2;

		if (i + 1 <= count && heap[i].val > heap[i + 1].val)
			i++;
	}

	return ret;
}

int dist[20001];

void dijkstra(GraphType* g, int k) {
	GraphNode v;
	v.val = 0;
	v.vertex = k;
	v.link = NULL;
	hpush(v);

	while (count) {
		GraphNode node = hpop();
		int d = node.val;
		if (node.val != dist[node.vertex]) continue;
		GraphNode* selectedNode = g->adj_list[node.vertex];
		while (selectedNode != NULL) {
			if (dist[selectedNode->vertex] > selectedNode->val + d) {
				dist[selectedNode->vertex] = selectedNode->val + d;
				v.val = dist[selectedNode->vertex];
				v.vertex = selectedNode->vertex;
				v.link = NULL;

				hpush(v);
			}

			selectedNode = selectedNode->link;
		}
	}
}

int main() {
	int V, e, k;
	int i;
	int u, v, w;
	GraphType g;
	init(&g);

	scanf("%d %d", &V, &e);
	scanf("%d", &k);
	g.n = V;
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insert_edge(&g, u, v, w);
	}
	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[k] = 0;
	dijkstra(&g, k);

	for (i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
			continue;
		}
		printf("%d\n", dist[i]);
	}

	return 0;
}
