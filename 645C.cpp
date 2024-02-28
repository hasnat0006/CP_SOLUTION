//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 13:19:47            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> faka;
    for (int i = 0; i < n; i++) 
        if (s[i] == '0')
            faka.push_back(i);
    dbg(faka);
    set<int> ans;
    for (int i = 0; i < faka.size() - k; i++) {
        int possibleMid = (faka[i] + ((faka[i + k] - faka[i]) / 2));
        int id = lower_bound(vf(faka), possibleMid) - faka.begin();
        for (int j = id - 1; j <= id + 1; j++)
            if (j >= i && j <= i + k)
                ans.insert(max(faka[j] - faka[i], faka[i + k] - faka[j]));
    }
    cout << *ans.begin() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}