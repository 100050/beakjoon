#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<ll> arr;
ll res = 0;

void merge(int first, int mid, int last) {
    int* sorted = new int[last - first + 1];
    int i, j, k;
    i = first;		// First arr idx
    j = mid + 1;	// Second arr idx
    k = 0;			// Sorted arr idx
    int tmp = 0;
    while (i <= mid && j <= last)
    {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
            res += tmp;
        }
        else {
            sorted[k++] = arr[j++];
            tmp++;
        }
    }

    if (i > mid)
        while (j <= last) sorted[k++] = arr[j++];
    else
        while (i <= mid) {
            sorted[k++] = arr[i++];
            res += tmp;
        }

    for (i = first, k = 0; i <= last; i++, k++) arr[i] = sorted[k];

    delete[] sorted;
}

void check(int b, int e) {
    if (b < e) {
        int mid = (b + e) / 2;

        check(b, mid);
        check(mid + 1, e);
        merge(b, mid, e);
    }
}

void solve() {
    int n;

    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    check(0, n - 1);


    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}