#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

int c = 0;
int p[8];
int arr[8];
bool visited[8];

bool ccw(pid p1, pid p2, pid p3) {
    double s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return 0;
}

void dfs(int d) {
    auto x = [](int d) { return arr[d] * cos(M_PI/4 * d); };
    auto y = [](int d) { return arr[d] * sin(M_PI/4 * d); };
    if (d > 2) {
        // 점 구하기
        if (ccw({ x(d-1), y(d-1) }, { x(d - 2), y(d - 2) }, { x(d - 3), y(d - 3) })) {
            int temp = 1;
            for (int i = 1; i <= 8-d; i++) {
                temp *= i;
             //   cout << arr[i-1] << " ";
            }
            //cout << c << " " << d << "\n";
            c += temp;
            return;
        }
    }
    if (d == 8) {
        if (ccw({ x(0), y(0) }, { x(7), y(7) }, { x(6), y(6) })) {
            //cout << c << "\n";
            c += 1;
            return;
        }
        if (ccw({ x(1), y(1) }, { x(0), y(0) }, { x(7), y(7) })) {
            //cout << c << "\n";
            c += 1;
        }
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (visited[j]) continue;
        visited[j] = true;
        arr[d] = p[j];
        dfs(d+1);
        visited[j] = false;
    }
}

void solve() {
    constexpr int total = 8 * 7 * 6 * 5 * 4 * 3 * 2;

    for (int i = 0; i < 8; i++) {
        cin >> p[i];
    }

    dfs(0);

    cout << (total-c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}