//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|11|2024 20:32:03            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
        diff[i] = b[i] - a[i];
    sort(vf(diff));
    dbgc(diff);
    int win = 0;
    for (int i = 0; i < n; i++) {
        if (diff[i] < 0)
            win++;
        else {
            if (x > diff[i]) {
                win++;
                x -=( diff[i] + 1);
            }
            else
                break;
        }
    }
    if (win >= (n + 1) / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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