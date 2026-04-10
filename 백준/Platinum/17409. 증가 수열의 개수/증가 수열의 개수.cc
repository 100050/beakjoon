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

// dp[l][n] = n까지 봤을 때 길이가 l인 증가 부분 수열의 개수
// st.second가 dp, st.first는 max 세그
vector<ll> st; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화
vector<ll> arr; // n으로 초기화
ll dp[11][100'001];

ll make_st(ll node, int start, int end) {
	if (start == end)
		return st[node] = 0; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	ll left = make_st(node * 2, start, mid);
	ll right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = (left + right) % MOD;

	return st[node];
}

void update(ll node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;
	st[node] += diff;
    st[node] %= MOD;

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

ll get(ll node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return st[node];

	int mid = (start + end) / 2;
    return (get(node * 2, start, mid, left, right) 
        + get(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

void solve(int CASE = -1) {
    int n, k;

    cin >> n >> k;
    arr.resize(n + 1);
    st.resize(1LL << ((int)ceil(log2(n + 1)) + 1));
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    //make_st(1LL, 0, n);

    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int l = 2; l <= k; l++) {
        fill(st.begin(), st.end(), 0);
        for (int i = 1; i <= n; i++) {
            update(1LL, 0, n, arr[i], dp[l - 1][i]);
            dp[l][i] = get(1LL, 0, n, 0, arr[i] - 1);
            // max 세그먼트 트리로 0~i-1까지 arr[i]보다 작은 원소의
            // dp[j]를 찾아 더함
            // max 세그먼트 트리에서 dp[i] 업데이트
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[k][i];
        res %= MOD;
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