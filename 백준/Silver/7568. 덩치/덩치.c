#include <stdio.h>
#include <stdlib.h>

typedef struct Body {
	int height;
	int weight;
	int rank;
}Body;

int main() {
	Body* bodies;
	int n, i, j;
	scanf("%d", &n);
	bodies = (Body*)malloc(sizeof(Body) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &bodies[i].weight, &bodies[i].height);
		bodies[i].rank = 1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (bodies[i].weight < bodies[j].weight && bodies[i].height < bodies[j].height)
				bodies[i].rank++;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", bodies[i].rank);
	}

	free(bodies);

	return 0;
}