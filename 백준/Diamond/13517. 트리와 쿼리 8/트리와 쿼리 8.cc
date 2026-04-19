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

int cnt = 0;
vector<pii> range;
vector<int> adj[100'001], tour, firstTour, n2s(1);

// pst, k번째로 작은 가중치

int n;
vector<Node> st; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화
vector<int> root, arr, par; // n으로 초기화

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

T get_k(int start, int end, int a, int b, int lca, int lca2, int k) {
	if (start == end) return start;

	int diff = st[st[b].l].v + st[st[a].l].v - st[st[lca].l].v - st[st[lca2].l].v;
	int mid = (start + end) / 2;
	//cout << diff << " " << k << "\n";

	if (diff >= k) return get_k(start, mid, st[a].l, st[b].l, st[lca].l, st[lca2].l, k);
	else return get_k(mid + 1, end, st[a].r, st[b].r, st[lca].r, st[lca2].r, k - diff);
}

// 오일러 투어 트릭, lca

using T2 = ll;
vector<T2> st2; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화

T2 make_st2(ll node, int start, int end) {
	if (start == end)
		return st2[node] = tour[start]; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	T2 left = make_st2(node * 2, start, mid);
	T2 right = make_st2(node * 2 + 1, mid + 1, end);
	st2[node] = min(left, right);

	return st2[node];
}

T2 get2(ll node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF<int>;
	if (left <= start && end <= right) return st2[node];

	int mid = (start + end) / 2;
	T2 l = get2(node * 2, start, mid, left, right);
	T2 r = get2(node * 2 + 1, mid + 1, end, left, right);

	return min(l, r);
}
vector<int> d, firstRoot;


void dfs(int x, int p) {
	range[x].first = ++cnt;

	tour.push_back(range[x].first);
	n2s.push_back(x);
	par[x] = p;

	firstTour[x] = tour.size() - 1;

	// p의 root를 찾아야 함
	st.push_back(st[root[range[p].first]]);
	root.push_back(st.size() - 1);
	update(root.back(), 0, 1'000'000, d[x], 1);


	for (int nxt : adj[x]) {
		if (nxt == p) continue;
		dfs(nxt, x);
		tour.push_back(range[x].first);
	}

	range[x].second = cnt;
}

void solve(int CASE = -1) {
	

    cin >> n;
	d.resize(n + 1); firstTour.resize(n + 1);
	par.resize(n + 1);
	range.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        
        cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
    }

	st.reserve(4'000'000);
	st.push_back({ -1, -1, 0});
	make_st(0LL, 0, 1'000'000);
	root.push_back(0);
	tour.push_back(0);
	dfs(1, 0);

	st2.resize(1LL << ((int)ceil(log2(tour.size())) + 1));
	make_st2(1LL, 1, tour.size() - 1);

	int m;

	cin >> m;
	while (m--) {
		int i, j, k;

		cin >> i >> j >> k;
		int ti = firstTour[i];
		int tj = firstTour[j];

		if (ti > tj) swap(ti, tj);
		int lca = get2(1LL, 1, tour.size() - 1, ti, tj);
		//cout << i << " " << j << " " << n2s[lca] << "\n";
		cout << get_k(0, 1'000'000, root[range[i].first], root[range[j].first], 
			root[range[n2s[lca]].first], root[range[par[n2s[lca]]].first], k) << "\n";
	}
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