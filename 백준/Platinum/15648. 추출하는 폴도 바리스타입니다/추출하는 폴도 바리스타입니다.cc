#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


using T = ll;
vector<T> st; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화
vector<ll> arr; // n으로 초기화

T make_st(ll node, int start, int end) {
	if (start == end)
		return st[node] = arr[start]; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	T left = make_st(node * 2, start, mid);
	T right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = max(left, right);

	return st[node];
}

void update(ll node, int start, int end, int index, T diff) {
	if (index < start || index > end) return;
    st[node] = max(diff, st[node]);

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

T get(ll node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return st[node];

	int mid = (start + end) / 2;
    T l = get(node * 2, start, mid, left, right);
    T r = get(node * 2 + 1, mid + 1, end, left, right);
    return max(l, r);
}

int dp[500000];
vector<int> dp2;

void solve(int CASE = -1) {
	int n, k, d;

	cin >> n >> k >> d;
	arr.resize(n);
	dp2.resize(k);
	st.resize(1LL << ((int)ceil(log2(500001)) + 1));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		int v = get(1LL, 0, 500000, max(arr[i] - d, 0LL), min(arr[i] + d, 500000LL)) + 1;
		v = max(v, dp2[arr[i] % k] + 1);
		dp[i] = v;
		dp2[arr[i] % k] = v;
		update(1LL, 0, 500000, arr[i], dp[i]);

		res = max(v, res);
	}

	cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}