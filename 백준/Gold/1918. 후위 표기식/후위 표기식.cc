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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void solve(int CASE = -1) {
    string str, res{ "" };
    string op{ "+-*/()" };
    vector<int> p{ 1, 1, 2, 2, 0, 0 };
    stack<char> s;

    cin >> str;

    for (const char& c : str) {
        int o = -1;
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == c) {
                o = i;
                break;
            }
        }
        
        if (o == -1) {
            res += c;
        }
        else {
            if (op[o] == '(' || s.empty())
                s.push(o);
            else {
                while (!s.empty() && p[s.top()] >= p[o]) {
                    //cout << op[o] << " " << op[s.top()] << "\n";
                    if (op[o] == ')' && op[s.top()] == '(') {
                        s.pop();
                        break;
                    }
                    if (s.top() < 4) res += op[s.top()];
                    s.pop();
                }
                if (op[o] != ')') s.push(o);
            }
        }
        //cout << o << " " << res << "\n";
    }

    while (!s.empty()) {
        if (s.top() < 4) res += op[s.top()];
        s.pop();
    }

    cout << res;
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