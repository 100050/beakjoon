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
//constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


using T = int;

struct Node {
	int l, r;
	T v;
};

int n;
vector<Node> st; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화
vector<int> idx, root, arr; // n으로 초기화

T make_st(ll node, int start, int end) {
	if (start == end)
		return (st[node] = { -1, -1, 0 }).v; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	st.push_back({ -1, -1, 0 });
	st[node].l = st.size() - 1;
	st.push_back({ -1, -1, 0 });
	st[node].r = st.size() - 1;
	T left = make_st(st[node].l, start, mid);
	T right = make_st(st[node].r, mid + 1, end);
	st[node].v = left + right;

	return st[node].v;
}

void update(ll node, int start, int end, int index, T diff) {
	if (start == end) {
		st[node].v += diff;
		return;
	}
	
	int mid = (start + end) / 2;
	if (index <= mid) {
		st.push_back(st[st[node].l]);
		st[node].l = st.size() - 1;
		update(st[node].l, start, mid, index, diff);
	}
	else {
		st.push_back(st[st[node].r]);
		st[node].r = st.size() - 1;
		update(st[node].r, mid + 1, end, index, diff);
	}
	
	st[node].v = st[st[node].l].v + st[st[node].r].v;
}



T get(ll node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return st[node].v;

	int mid = (start + end) / 2;
	T l = get(st[node].l, start, mid, left, right);
	T r = get(st[node].r, mid + 1, end, left, right);

	return l + r;
}

T get(int version, int left, int right) {
	return get(root[version], 0, n - 1, left, right);
}

T get_k(int start, int end, int left, int right, int k) {
	if (start == end) return start;

	int diff = st[st[right].l].v - st[st[left].l].v;
	int mid = (start + end) / 2;

	if (diff >= k) return get_k(start, mid, st[left].l, st[right].l , k);
	else return get_k(mid + 1, end, st[left].r, st[right].r, k - diff);
}

ll res = 0;



void dfs(int start, int end) {
	if (end - start + 1 <= 1) return;

	res += end - start + 1;

	int k = get_k(0, n - 1, root[start - 1], root[end], (end - start) / 2 + 1);

	dfs(start, arr[k]-1);
	dfs(arr[k] + 1, end);
}

void solve(int CASE = -1) {
    
    cin >> n;
	idx.resize(n); arr.resize(n);
    for (int i = 0; i < n; i++) {
        int t;
        
        cin >> t;
		arr[i] = t;
		t--;
		idx[t] = i;
    }
	st.push_back({ -1, -1, 0 });
	make_st(0LL, 0, n - 1);
	root.push_back(0);
	for (int i = 0; i < n; i++) { // i: 값
		st.push_back(st[root.back()]);
		root.push_back(st.size() - 1);
		update(root.back(), 0, n - 1, idx[i], 1);
	}

	dfs(1, n);
    
	cout << res << "\n";
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