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


using T = array<ll, 3>;
int n;
vector<T> st; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화
vector<ll> arr, psum; // n으로 초기화

T make_st(ll node, int start, int end) {
	if (start == end)
        return st[node] = { arr[start], arr[start], arr[start] }; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	T left = make_st(node * 2, start, mid);
	T right = make_st(node * 2 + 1, mid + 1, end);
	st[node][0] = max(left[0], right[0] + psum[mid] - psum[start-1]);
    st[node][1] = max(right[1], left[1] + psum[end] - psum[mid]);
    st[node][2] = max(left[1] + right[0], max(left[2], right[2]));

	return st[node];
}

T get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return { -100'000'000, -100'000'000, -100'000'000 };
	if (left <= start && end <= right) return st[node];

	int mid = (start + end) / 2;

    T l = get(node * 2, start, mid, left, right);
    T r = get(node * 2 + 1, mid + 1, end, left, right);
    T tmp;

    tmp[0] = max(l[0], r[0] + psum[mid] - psum[start - 1]);
    tmp[1] = max(r[1], l[1] + psum[end] - psum[mid]);
    tmp[2] = max(l[1] + r[0], max(l[2], r[2]));

    return tmp;
}



void solve(int CASE = -1) {
    
    cin >> n;
    arr.resize(n + 1);
    psum.resize(n + 1);
    st.resize(1LL << ((int)ceil(log2(n + 1)) + 1));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    make_st(1LL, 1, n);

    int m;
    cin >> m; 
    while (m--) {
        int i, j;
        cin >> i >> j;

        cout << get(1LL, 1, n, i, j)[2] << "\n";
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