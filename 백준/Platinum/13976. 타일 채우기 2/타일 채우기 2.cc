#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
//const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct Matrix {
    ll a, b, c, d;
};

Matrix power(Matrix A, ll n) {
    if (n == 1) {
        return A;
    }

    // 행렬곱
    auto mm = [](Matrix& A, Matrix& B) {
        Matrix C = {
            ((A.a * B.a + MOD) % MOD + (A.b * B.c + MOD) % MOD) % MOD,
            ((A.a * B.b + MOD) % MOD + (A.b * B.d + MOD) % MOD) % MOD,
            ((A.c * B.a + MOD) % MOD + (A.d * B.c + MOD) % MOD) % MOD,
            ((A.c * B.b + MOD) % MOD + (A.d * B.d + MOD) % MOD) % MOD
        };
        return C;
        };

    if (n % 2 == 1) {
        Matrix B = power(A, n - 1);

        return mm(B, A);
    }
    else {
        Matrix B = power(A, n / 2);

        return mm(B, B);
    }
}

void solve(int CASE = -1) {
    ll n;

    cin >> n;

    // 실제 답 계산
    if (n % 2 == 1) {
        cout << 0;
        return;
    }
    
    n /= 2;
    if (n == 1) {
        cout << 3;
        return;
    }

    Matrix A = power({ 4, -1, 1, 0 }, n - 1);

    cout << ((A.a * 3) % MOD + A.b * 1 + MOD) % MOD;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}