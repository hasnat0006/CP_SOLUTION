//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|03|2024 01:01:33            !//
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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; j++)
            cin >> a[j];
        int need = a.front() + 1;
        for (int j = 1; j < k; j++) {
            if (a[j] >= need)
                need = a[j] + 1;
            else
                need++;
        }
        // dbg(need);
        v[i] = {need - k + 1, k};
    }
    sort(vf(v));
    dbg(v);
    auto isPossible = [&](int x) {
        int time = 0;
        for (int i = 0; i < n; i++) {
            if(x < v[i].first)
                return false;
            x += v[i].second ;
        }
        return true;
    };

    int low = 0, high = (int)1e18, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        dbg(mid, isPossible(mid));
        if (isPossible(mid)) {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
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