//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 11:44:22            !//
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

int tillX(int x) { return (x * (x + 1)) / 2; }
int tillXminus1(int x) { return (x * (x - 1)) / 2; }

void solve() {
    int k, x;
    cin >> k >> x;
    int level = 2 * k - 1;
    int total = (tillX(k) + tillXminus1(k));
    int msg = level * (x / total);
    x = x % total;
    int low = 0, high = level, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int emoji = 0;
        if (mid > k) {
            emoji += tillX(k);
            int baki = mid - k;
            int bad = k - 1 - baki;
            emoji += (tillXminus1(k) - tillX(bad));
        }
        else
            emoji = tillX(mid);
        if (emoji <= x) {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    int emoji = 0;
    if (ans > k) {
        emoji += tillX(k);
        int baki = ans - k;
        int bad = k - 1 - baki;
        emoji += (tillXminus1(k) - tillX(bad));
    }
    else
        emoji = tillX(ans);
    if(x - emoji > 0)
        ans++;
    cout << min(level, ans + msg) << endl;
    // dbg(low, high, ans, x, emoji, msg);
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