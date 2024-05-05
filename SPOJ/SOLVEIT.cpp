//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> m;
    while (q--) {
        int ch, val;
        cin >> ch >> val;
        if (ch == 1)
            m[val] = -1;
        else {
            auto x = m.lower_bound(val);
            if (x == m.end())
                cout << "-1\n";
            else
                cout << x->first << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}