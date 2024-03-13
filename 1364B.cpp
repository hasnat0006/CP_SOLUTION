//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 01:23:42            !//
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
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int diff = 0;
    for (int i = 1; i < n; i++)
        diff += abs(a[i] - a[i - 1]);
    vector<int> ans;
    int pre = a.front();
    int inc = 0, dec = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > pre) {
            if (inc == 1)
                pre = a[i];
            else {
                ans.push_back(pre);
                pre = a[i];
            }
            inc = 1;
            dec = 0;
        }
        else if (a[i] < pre){
            if (dec == 1)
                pre = a[i];
            else {
                ans.push_back(pre);
                pre = a[i];
            }
            dec = 1;
            inc = 0;
        }
        // dbg(i, ans);
    }
    ans.push_back(a.back());
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
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