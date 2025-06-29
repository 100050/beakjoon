#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <sstream>
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

class Opinion {
public:
    long double time;
    int l;
    long double p;
    ll month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    ll begin;
    void set(int year) {
        if (year == 2020) month[2] = 29;
        for (int i = 1; i < 13; i++) {
            month[i] += month[i - 1];
        }

    }

    Opinion(string t1, string t2, int ll) : l(ll) {
        string tmp;
        int idx = 0;

        tmp = t1.substr(idx, t1.find('/', idx + 1)); // 년
        idx = t1.find('/', idx + 1) + 1;
        set(stoi(tmp));
        time = 0;
        if (stoi(tmp) > 2020) {
            time += (stoll(tmp) - 2020) * 365;
            time += 366;
        }
        else {
            time += (stoll(tmp) - 2019) * 365;
        }

        tmp = t1.substr(idx, t1.find('/', idx + 1) - idx); // 월
        idx = t1.find('/', idx + 1) + 1;
        time += month[stoi(tmp) - 1];
        //cout << stoi(tmp) << " ";
        tmp = t1.substr(idx, t1.find('/', idx + 1) - idx); // 일
        idx = t1.find('/', idx + 1) + 1;
        time += stoll(tmp);
        //cout << stoll(tmp) << " ";

        idx = 0;
        tmp = t2.substr(idx, t2.find(':', idx + 1) - idx); // 시
        idx = t2.find(':', idx + 1) + 1;
        time += (stold(tmp)) / 24;
        //cout << stold(tmp) / 24 << " ";
        tmp = t2.substr(idx, t2.find(':', idx + 1) - idx); // 분
        idx = t2.find(':', idx + 1) + 1;
        time += stold(tmp) / (24 * 60);
        //cout << stold(tmp) / (24 * 60) << " ";
        tmp = t2.substr(idx, t2.find(':', idx + 1) - idx); // 초
        idx = t2.find(':', idx + 1) + 1;
        time += stold(tmp) / (24 * 60 * 60);
        //cout << stold(tmp) / (24 * 60 * 60) << " ";
        //cout << time;
        //cout << endl;

    }

    void calculate(long double mxT, int i, int n) {
        p = max(pow(0.5L, (mxT - time) / (long double)(365)), pow(0.9L, (long double)(n - i)));
        //cout << i << " " << p << endl;
    }

};

int compare(const Opinion& a, const Opinion& b) {
    // a, b 비교
    return a.time <= b.time;
}

void solve() {
    int n;
    int l;
    string t1, t2;
    vector<Opinion> o;

    cin >> n;
    if (n == 0) {
        cout << 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2 >> l;

        o.push_back(Opinion(t1, t2, l));
    }

    sort(o.begin(), o.end(), compare);


    // p 구하기
    for (int i = 1; i <= n; i++) {
        //cout << o[i].time << endl;
        o[i - 1].calculate(o[o.size() - 1].time, i, n);
    }

    long double x = 0;
    long double s = 0;

    for (int i = 0; i < n; i++) {
        // x구하기
        x += o[i].p * o[i].l;
        s += o[i].p;
    }
    //cout << x << " ";
    //cout << s << " ";
    x /= s;
    //cout << x << endl;;
    cout << round(x);
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