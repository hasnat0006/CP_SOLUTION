//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define endl '\n'
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void balance(multiset<int> &x, multiset<int> &y) {
    while (true) {
        int sizex = x.size();
        int sizey = y.size();
        if (sizex == sizey || sizex == sizey + 1)
            break;
        if (sizex < sizey) {
            auto it = y.begin();
            x.insert(*it);
            y.erase(it);
        }
        else {
            auto it = x.end();
            --it;
            y.insert(*it);
            x.erase(it);
        }
    }
}

void add(multiset<int> &x, multiset<int> &y, int value) {
    if (x.empty())
        x.insert(value);
    else {
        auto it = x.end();
        it--;
        if (value < *it)
            x.insert(value);
        else
            y.insert(value);
    }
}

void solve() {
    multiset<int> small, big;
    while (1) {
        int x;
        cin >> x;
        if (x == 0)
            break;
        else if (x == -1) {
            auto it = small.end();
            it--;
            cout << *it << endl;
            small.erase(it);
            if (small.size() < big.size()) {
                auto it = big.begin();
                small.insert(*it);
                big.erase(it);
            }
        }
        else {
            add(small, big, x);
            balance(small, big);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}