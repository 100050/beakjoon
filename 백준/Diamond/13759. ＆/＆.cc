#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 10^6은 2^20보다 작으므로 m = 20이 적당합니다.
const int M = 20;
const int MAX_VAL = (1 << M);

// dp[mask]: mask를 하위 비트로 가지는 A의 원소들을 모두 AND 연산한 결과
int dp[MAX_VAL];
bool has_superset[MAX_VAL]; // 해당 mask를 포함하는 숫자가 A에 존재하는지 체크

void solve() {
    int n;
    if (!(cin >> n)) return;

    // 1. 초기화: AND의 항등원은 모든 비트가 1인 값입니다.
    // 하지만 존재하지 않는 구간을 구분하기 위해 초기값 설정에 주의해야 합니다.
    for (int i = 0; i < MAX_VAL; i++) {
        dp[i] = (1 << M) - 1;
        has_superset[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        dp[t] = t;
        has_superset[t] = true;
    }

    // 2. SOS DP (Superset AND)
    // i번째 비트가 꺼져있는 s에 대하여, i번째 비트가 켜진 상위 집합(s | 1<<i)의 AND 결과를 합침
    for (int i = 0; i < M; i++) {
        for (int s = 0; s < MAX_VAL; s++) {
            if (!(s & (1 << i))) {
                int superset = s | (1 << i);
                // 상위 집합에 데이터가 있는 경우에만 AND 연산 수행
                if (has_superset[superset]) {
                    dp[s] &= dp[superset];
                    has_superset[s] = true;
                }
            }
        }
    }

    // 3. 결과 카운팅
    int res = 0;
    bool zero_counted = false;

    for (int i = 0; i < MAX_VAL; i++) {
        // dp[i] == i: i를 포함하는 상위 비트들을 AND했더니 정확히 i가 나옴
        if (has_superset[i] && dp[i] == i) {
            res++;
            if (i == 0) zero_counted = true;
        }
    }

    // 부분 배열 크기가 0일 때 AND 값은 0이므로, 0이 아직 안 세졌다면 추가
    if (!zero_counted) res++;

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}