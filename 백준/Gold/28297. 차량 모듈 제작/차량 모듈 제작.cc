#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);

struct Circle {
    ld x, y, r;
};

struct V {
    int a, b;
    ld w;
};

vector<int> parent;
vector<Circle> arr;
vector<V> v;
ld res;

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(V& v) {
    int aa = Find(v.a);
    int bb = Find(v.b);

    if (aa == bb) return;

    parent[bb] = aa;
    res += v.w;
}

double calculate_distance(double x1, double y1, double r1, double x2, double y2, double r2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double get_belt_length(double x1, double y1, double r1, double x2, double y2, double r2) {
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    double d = calculate_distance(x1, y1, r1, x2, y2, r2);
    if (d <= r1 + r2) return 0.0;

    double h = sqrt(d * d - (r1 - r2) * (r1 - r2));
    double theta = acos((r1 - r2) / d);
    double arc_length_1 = r1 * 2 * (PI - theta);
    double arc_length_2 = r2 * 2 * theta;

    return 2 * h + arc_length_1 + arc_length_2;
}

void solve() {
    int n;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].r;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld length = get_belt_length(arr[i].x, arr[i].y, arr[i].r, arr[j].x, arr[j].y, arr[j].r);

            v.push_back({ i, j, length });
        }
    }

    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    sort(v.begin(), v.end(), [](const V& a, const V& b) { return a.w < b.w; });

    for (int i = 0; i < v.size(); i++) {
        V& t = v[i];

        Union(t);
    }

    cout.precision(6);
    cout << fixed;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}