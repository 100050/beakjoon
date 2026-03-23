#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    int n;
    vector<ll> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. 팩토리얼 사전 계산 ((k-1)! 사용)
    vector<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    vector<ll> cycle_ways(1 << n, 0);
    for (int mask = 1; mask < (1 << n); ++mask) {
        int size = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) size++;
        }

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                // 순환의 길이는 각 원소의 Ai의 약수여야 함
                if (arr[i] % size != 0) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            //if (size > 1) size--;
            cycle_ways[mask] = fact[size - 1];
        }
    }

    // 3. 비트마스크 DP 진행
    vector<ll> dp(1 << n, 0);
    dp[0] = 1; // 아무것도 선택하지 않은 상태의 경우의 수는 1

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == 0) continue;

        // 아직 포함되지 않은 원소들의 집합
        int remaining = ((1 << n) - 1) ^ mask;
        if (remaining == 0) continue;

        // 중복 방지를 위한 핵심: 남은 원소 중 가장 작은 인덱스(LSB)를 찾음
        int first = 0;
        while (!((remaining >> first) & 1)) {
            first++;
        }

        // remaining의 모든 부분집합(sub)을 순회하는 테크닉
        // sub는 반드시 'first' 원소를 포함해야 함 (중복 방지)
        for (int sub = remaining; sub > 0; sub = (sub - 1) & remaining) {
            if ((sub >> first) & 1) {
                if (cycle_ways[sub] > 0) {
                    dp[mask | sub] += dp[mask] * cycle_ways[sub];
                }
            }
        }
    }

    // 모든 원소를 다 사용한 상태의 결과 출력
    cout << dp[(1 << n) - 1];

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