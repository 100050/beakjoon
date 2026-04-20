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


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> sa, r;
vector<int> getSA(const string& s) {
    int n = s.length();
    int m = max(256, n); // 문자셋 크기 또는 n
    sa.resize(n); r.resize(n);
    vector<int>  tmp(n), cnt(m);

    // 초기 단계: 길이 1에 대해 정렬 및 순위 부여
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
        sa[i] = i;
        r[i] = s[i];
    }
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--cnt[s[i]]] = i;

    for (int k = 1; k < n; k <<= 1) {
        // 1. 길이에 따른 두 번째 키 기준 정렬 (Counting Sort 생략 가능 부분 최적화)
        int p = 0;
        for (int i = n - k; i < n; i++) tmp[p++] = i;
        for (int i = 0; i < n; i++) {
            if (sa[i] >= k) tmp[p++] = sa[i] - k;
        }

        // 2. 첫 번째 키 기준 Counting Sort
        fill(cnt.begin(), cnt.begin() + m, 0);
        for (int i = 0; i < n; i++) cnt[r[tmp[i]]]++;
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[r[tmp[i]]]] = tmp[i];

        // 3. 새로운 순위(Rank) 계산
        vector<int> newRank(n);
        newRank[sa[0]] = 0;
        p = 1;
        for (int i = 1; i < n; i++) {
            // (rank[sa[i]], rank[sa[i]+k]) 쌍이 이전과 같은지 비교
            auto prev = make_pair(r[sa[i - 1]], (sa[i - 1] + k < n ? r[sa[i - 1] + k] : -1));
            auto curr = make_pair(r[sa[i]], (sa[i] + k < n ? r[sa[i] + k] : -1));
            newRank[sa[i]] = (prev == curr ? p - 1 : p++);
        }
        r = newRank;
        if (p == n) break; // 모든 순위가 결정되면 조기 종료
        m = p; // 다음 단계를 위해 정렬 범위 축소
    }
    return sa;
}

vector<int> buildLCP(const string& t, const vector<int>& sa, const vector<int>& rank) {
    int n = t.size();
    vector<int> lcp(n, 0);
    int h = 0;

    for (int i = 0; i < n; i++) {
        // rank[i]가 0이면 Suffix Array에서 가장 앞선 것이므로 비교 대상이 없음
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1]; // SA에서 바로 이전 순위의 접미사 인덱스

            // h는 이전 단계에서 1 줄어든 상태로 시작 (0보다 작아질 수 없음)
            if (h > 0) h--;

            // i+h, j+h부터 시작하여 실제로 문자가 같은지 비교
            while (i + h < n && j + h < n && t[i + h] == t[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
        }
    }
    return lcp;
}

void solve(int CASE = -1) {
    string t;
    cin >> t;

    getSA(t);
    
    vector<int> lcp = buildLCP(t, sa, r);
    ll ret = 0;
    for (int i = 0; i < t.size(); i++) {
        ret += lcp[i];
    }
    ll n = t.size();
    cout << ((n + 1) * n) / 2 - ret;
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