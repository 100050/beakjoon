#include <stdio.h>

int arr[1000001] = { 0, };

int Find(int temp) {
	if (arr[temp] == temp)
		return temp;
	else
		return arr[temp] = Find(arr[temp]);
}

void Union(int x, int y) {
	int nx, ny;

	nx = Find(x);
	ny = Find(y);

	if (nx != ny) {
		arr[nx] = ny;
	}
}

int main() {
	int n, m, a, b, c;
	int i, x, y;

	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++) {
		arr[i] = i;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		if (a) {
			x = Find(b);
			y = Find(c);

			if (x == y)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			Union(b, c);
		}
	}

	return 0;
}