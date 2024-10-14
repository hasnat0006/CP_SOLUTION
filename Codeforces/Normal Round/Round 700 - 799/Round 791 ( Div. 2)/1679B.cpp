//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    int sum = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        mp[i] = v[i];
    }
    int last_inserted = 0;
    while (q--) {
        int ch, id, x;
        cin >> ch;
        if (ch == 1) {
            cin >> id >> x;
            sum = (mp.empty() || !mp[id]) ? sum - last_inserted + x : sum - mp[id] + x;
            mp[id] = x;
            cout << sum << endl;
        }
        else {
            cin >> x;
            sum = n * x, last_inserted = x, mp.clear();
            cout << sum << endl;
        }
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
