#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ll long long

int n;
ll arr[100000];

ll dc(int left, int right) {
	if (left == right) {
		return arr[left];
	}
	
	int middle = (left + right) / 2;

	ll big_left = dc(left, middle);
	ll big_right = dc(middle + 1, right);
	ll big = big_left > big_right ? big_left : big_right;
	ll mxh;

	int _left = middle - 1;
	int _right = middle + 1;
	int width = 1;
	mxh = arr[middle];

	while (left <= _left || _right <= right) {
		if (left > _left) {
			if (mxh > arr[_right])
				mxh = arr[_right];
			_right++;
		}
		else if (_right > right) {
			if (mxh > arr[_left])
				mxh = arr[_left];
			_left--;
		}
		else {
			if (arr[_left] < arr[_right]) {
				if (mxh > arr[_right])
					mxh = arr[_right];
				_right++;
			}
			else {
				if (mxh > arr[_left])
					mxh = arr[_left];
				_left--;
			}
		}
		width++;

		if (big < mxh * width) {
			big = mxh * width;
		}
	}
	//printf("53 %d %d %d %lld\n", left, middle, right, big);

	return big;
}

int solve() {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%lld\n", dc(0, n - 1));
	
}

int main() {
	
	scanf("%d", &n);
	while (n) {
		solve();

		scanf("%d", &n);
	}

	return 0;
}