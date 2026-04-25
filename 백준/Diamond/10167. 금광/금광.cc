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


using T = array<ll, 4>;
int n, m;
vector<T> st; // 4*n or 1LL << ((int)ceil(log2(n)) + 1)으로 초기화
vector<array<ll, 3>> arr;

T make_st(ll node, int start, int end) {
	if (start == end)
        return st[node] = { 0, 0, 0, 0 }; // 초기화 값 필요하다면 변경
	int mid = (start + end) / 2;
	T left = make_st(node * 2, start, mid);
	T right = make_st(node * 2 + 1, mid + 1, end);
	st[node][0] = max(left[0], right[0] + left[3]);
    st[node][1] = max(right[1], left[1] + right[3]);
    st[node][2] = max(left[1] + right[0], max(left[2], right[2]));
    st[node][3] = left[3] + right[3];

	return st[node];
}

void update(ll node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);

        st[node][0] = max(st[node*2][0], st[node * 2 + 1][0] + st[node * 2][3]);
        st[node][1] = max(st[node * 2 + 1][1], st[node * 2][1] + st[node * 2 + 1][3]);
        st[node][2] = max(st[node * 2][1] + st[node * 2 + 1][0], max(st[node * 2][2], st[node * 2 + 1][2]));
        st[node][3] = st[node * 2][3] + st[node * 2 + 1][3];

    }
    else {
        st[node][0] += diff;
        st[node][1] += diff;
        st[node][2] += diff;
        st[node][3] += diff;
    }
}

T get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return { -100'000'000, -100'000'000, -100'000'000 };
	if (left <= start && end <= right) return st[node];

	int mid = (start + end) / 2;

    T l = get(node * 2, start, mid, left, right);
    T r = get(node * 2 + 1, mid + 1, end, left, right);
    T tmp;

    tmp[0] = max(l[0], r[0] + l[3]);
    tmp[1] = max(r[1], l[1] + r[3]);
    tmp[2] = max(l[1] + r[0], max(l[2], r[2]));
    tmp[3] = l[3] + r[3];

    return tmp;
}



void solve(int CASE = -1) {
    vector<int> x, y;

    int nn;
    cin >> nn;
    arr.resize(nn);
    for (int i = 0; i < nn; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        x.push_back(arr[i][0]);
        y.push_back(arr[i][1]);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    for (int i = 0; i < nn; i++) {
        arr[i][0] = lower_bound(x.begin(), x.end(), arr[i][0]) - x.begin();
        arr[i][1] = lower_bound(y.begin(), y.end(), arr[i][1]) - y.begin();
    }

    n = x.size();
    m = y.size();

    sort(arr.begin(), arr.end(), [](const array<ll, 3>& a, const array<ll, 3>& b) {
        if (a[0] < b[0]) return true;
        else if (a[0] == b[0] && a[1] < b[1]) return true;
        else return false;
        });

    st.resize(1LL << ((int)ceil(log2(m)) + 1));
    
    ll res = 0;
    for (int i = 0; i < nn; i++) {
        if (i != 0 && arr[i][0] == arr[i - 1][0]) continue;

        make_st(1LL, 0, m-1);
        for (int j = i; j < nn; j++) {
            update(1LL, 0, m - 1, arr[j][1], arr[j][2]);
            if (j == nn - 1 || arr[j][0] != arr[j + 1][0]) 
                res = max(res, get(1LL, 0, m - 1, 0, m - 1)[2]);
        }
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