#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    int respA;

    srand(time(0));

    vector<int> randNum(10000);
    for (int i = 0; i < 10000; i++)
        randNum[i] = i + 1;
    random_shuffle(randNum.begin(), randNum.end());

    for (int a = 1; a <= 10000; a++)
    {
        std::cout << "? A " << randNum[a] << endl;
        std::cin >> respA;

        if (respA == 1)
        {
            int respB;
            int ansA = randNum[a];

            for (int b = 1; b <= 10000; b++)
            {
                std::cout << "? B " << randNum[b] << endl;
                std::cin >> respB;

                if (respB == 1)
                {
                    int ansB = randNum[b];
                    std::cout << "! " << ansA + ansB << endl;
                    return;
                }
            }
        }
    }

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