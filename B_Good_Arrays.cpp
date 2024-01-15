//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++, sum += v[i];
    dbg(sum);
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    if (mp.size() == n) {
        cout << "YES\n";
        return;
    }
    vector<int> temp;
    int diff = 0;
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)
            temp.pb(2), sum -= 2, diff = max(diff, 2 - v[i]);
        else
            temp.pb(1), sum--, diff = max(diff, v[i] - 1);
    }
    dbg(sum);
    if (sum < 0)
        cout << "NO\n";
    else {
        temp.pb(sum);
        cout << "YES\n";
        dbg(temp);
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}