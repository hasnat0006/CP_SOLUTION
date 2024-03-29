//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|03|2024 02:37:50            !//
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    map<int, vector<int>> schools;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        schools[v[i]].push_back(temp);
    }
    int mx = 0;
    vector<int> ans(n + 1, 0);
    for (auto &i : schools) {
        sort(vr(i.second));
        mx = max(mx, (int)i.second.size());
        for (int j = 1; j < i.second.size(); j++)
            i.second[j] += i.second[j - 1];
        for (int j = 1; j <= i.second.size(); j++) {
            int temp = i.second.size() % j;
            if (temp == 0)
                ans[j] += i.second.back();
            else {
                int id = i.second.size() - 1 - temp;
                ans[j] += (id >= 0) ? i.second[id] : 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}