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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void solve(int CASE = -1) {
    int n, m;
    vector<int> A;

    cin >> n;
    m = (n * (n - 1)) / 2;
    A.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    if (n == 2) {
        if (A[0] < 0) {
            cout << A[0] << " " << 0 << "\n";
        }
        else {
            cout << 0 << " " << A[0] << "\n";
        }
        return;
    }

    sort(A.begin(), A.end());
    for (int i = 2; i < m; i++) {
        vector<int> B;

        int B1 = A[0] + A[1] - A[i];

        if (B1 % 2 == 0) {
            map<int, int> vis;
            for (int j = 2; j < m; j++) {
                if (i == j) continue;
                vis[A[j]]++;
            }
            B.push_back(B1 / 2); // B1

            B.push_back(A[0] - B[0]); // B2
            B.push_back(A[1] - B[0]); // B3

            bool flag = false;
            while (B.size() != n) {
                auto it = vis.begin();

                //cout << Amn << "\n";
                B.push_back(it->first - B[0]);
                it->second--;
                if (it->second == 0) {
                    vis.erase(it);
                }

                flag = false;
                for (int j = 1; j < B.size() - 1; j++) {
                    auto it = vis.find(B.back() + B[j]);
                    if (it != vis.end()) {
                        it->second--;
                        if (it->second == 0) {
                            vis.erase(it);
                        }
                    }
                    else {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }

            if (B.size() == n && flag == false) {
                //sort(B.begin(), B.end());
                for (int i = 0; i < n; i++) {
                    cout << B[i] << " ";
                }
                return;
            }
        }
    }

    cout << "Impossible";
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