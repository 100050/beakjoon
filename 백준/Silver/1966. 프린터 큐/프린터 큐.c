#include <stdio.h>

int main() {
	int t, n, m;
	int i;
	int arr[100] = { 0, };
 
	scanf("%d", &t);
 
	while(t--) {
		scanf("%d %d", &n, &m);
		int ans = 1;
		int front = 0;
		int max = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
 
		while (1) {
			for (i = 0; i < n; i++) {
				if (arr[i] > max) max = arr[i];
			}
 
			while (arr[front] != max)
				front = (front + 1) % n;
 
			if (front == m) break;
 
			arr[front] = 0;
			front = (front + 1) % n;
			max = 0;
			ans++;
		}
		printf("%d\n", ans);
	}
    
	return 0;
}
