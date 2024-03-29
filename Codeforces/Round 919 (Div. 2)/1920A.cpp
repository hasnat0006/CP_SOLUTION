//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
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
    int big = 0, small = inf, equal = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            big = max(big, y);
        }
        else if (x == 2) {
            small = min(small, y);
        }
        else {
            mp[y] = 1;
        }
    }
    // cout << "___" << endl;
    if (big > small) {
        cout << 0 << endl;
        return;
    }
    dbg(big, small);
    // dbg(mp);
    int cnt = 0;
    vector<int> ans;
    for (auto i : mp) {
        ans.push_back(i.first);
    }
    dbg(ans);
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= big)
            break;
        cnt++;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] <= small)
            break;
        cnt++;
    }
    int bad = ans.size() - cnt;
    int good = small - big + 1 - bad;
    dbg(cnt, bad, good);
    cout << good << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i);
        solve();
    }
    return 0;
}