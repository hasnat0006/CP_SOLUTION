//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += abs(x);
        if (x != 0)
            v.pb(x);
    }
    int f = 1, c = 0;
    map<int, vector<int>> mp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0)
            mp[f].pb(v[i]);
        else
            f++;
    }
    // debug(c);
    cout << sum << " " << mp.size() << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}