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
    int n, x;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[i] = {x, i + 1};
    }
    sort(vf(v));
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        if (v[i].first % v[i - 1].first) {
            ans.emplace_back(v[i].second, (v[i - 1].first - (v[i].first % v[i - 1].first)));
            v[i].first += (v[i - 1].first - (v[i].first % v[i - 1].first));
        }
        dbg(v);
    }
    sort(vf(ans));
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
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