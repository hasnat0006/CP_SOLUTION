//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|04|2024 21:43:06            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    auto check = [&](int x, int K) {
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                int need = x - a[i];
                if (need <= K)
                    K -= need;
                else
                    return -1ll;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > x)
                cnt++;
        return cnt + K;
    };
    int low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int extra = check(mid, k);
        if(extra == -1)
            high = mid - 1;
        else{
            ans = n * (mid - 1) + extra + 1;
            low = mid + 1;
        }
        dbg(mid, extra, ans);
    }
    cout << ans << endl;
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