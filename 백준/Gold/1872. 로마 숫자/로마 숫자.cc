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

vector<char> parsing(string sentence) {
    vector<char> ret;

    for (const char c : sentence) {
        switch (c) {
        case 'i':
        case 'v':
        case 'x':
        case 'l':
        case 'c':
        case 'd':
        case 'm':
            ret.push_back(c);
            break;
        default:
            break;
        }
    }

    return ret;
}

void solve(int CASE = -1) {
    int n;
    const vector<char> digit{ 'm', 'd', 'c', 'l', 'x', 'v', 'i'};
    const vector<int> digit2{ 1000, 500, 100, 50, 10, 5, 1 };
        
    cin >> n;
    cin.ignore();

    while (n--) {
        string sentence;
        getline(cin, sentence);
        
        auto number = parsing(sentence);

        int mx = 0, large = 0;
        for (const char c : number) {
            for (int i = 0; i < digit.size(); i++) {
                if (digit[i] == c) {
                    if (mx < digit2[i]) {
                        mx = digit2[i];
                        large = i;
                    }
                    break;
                }
            }
        }

        int last = 0, res = 0, flag3 = 0;
        while (large != digit.size()) {
            // digit[large]가 끝나는 곳 찾기
            int count = 0;
            int flag2 = 0; // 90이나 40같은 숫자가 있는 경우
            for (int i = last; i < number.size(); i++) {
                // m이 아닐 때 large가 짝수이면 최대 3개이니 3, 
                // 홀수이면 최대 1개이니 0과 비교
                // large가 0일 때는 예외
                //cout << i << " " << large << " " << flag3 << "\n";
                if ((large != 0 && large % 2 == 0 && count == 3) || flag3 == 1) {
                    // large가 짝수인 경우 3번의 같은 수가 나온 뒤에 
                    // cl, cx 등을 찾아봐야 한다.
                    if (large % 2 == 0) {
                        if (large == digit.size() - 1) break;
                        bool flag = false;
                        for (int i = last; i < number.size(); i++) {
                            if (flag && number[i] == digit[large]) {
                                last = i + 1;
                                res += digit2[large] - digit2[large + 2];
                                flag2 = 1;
                                //cout << res << " " << flag3 << "\n";
                                flag3 = 1;
                                break;
                            }
                            else if (number[i] == digit[large + 2]) {
                                flag = true;
                            }
                        }
                        if (flag2) break;
                    }
                    else {
                        bool flag = false;
                        for (int i = last; i < number.size(); i++) {
                            if (flag && number[i] == digit[large]) {
                                last = i + 1;
                                res += digit2[large] - digit2[large + 1];
                                flag2 = 1;
                                flag3 = 1;
                                break;
                            }
                            else if (number[i] == digit[large + 1]) {
                                flag = true;
                            }
                        }
                        if (flag2) break;
                    }
                    flag3 = 0;
                    break;
                }
                else if (large % 2 == 1 && count == 1) break;

                if (number[i] == digit[large]) {
                    count++;
                    last = i + 1;
                }
            }
            res += count * digit2[large];
            large += 1 + flag2;
        }

        cout << res << "\n";
    }
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