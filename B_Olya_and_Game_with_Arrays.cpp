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
    int n;
    cin >> n;
    vector<int> v[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> temp(x);
        for (int j = 0; j < x; j++)
            cin >> temp[j];
        v[i] = temp;
        sort(vf(v[i]));
        dbg(v[i]);
    }
    int ans = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        a.pb(v[i][0]), b.pb(v[i][1]);
    }
    sort(vf(a));
    sort(vf(b));
    dbg(a, b);
    for (auto i : b)
        ans += i;
    dbg(ans);
    ans -= b[0];
    dbg(ans);
    ans += a[0];
    cout << ans << endl;
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