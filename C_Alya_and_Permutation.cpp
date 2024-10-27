//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|10|2024 21:09:48            !//
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
    int n;
    cin >> n;

    auto find_max = [](vector<ll> &v) {
        int mx = 0, N = v.size();
        for (int i = 0; i < N; i++) {
            if (i % 2)
                mx |= v[i];
            else
                mx &= v[i];
        }
        return mx;
    };

    vector<ll> ans(n, 0);

    if (n % 2) {
        iota(vf(ans), 1);
        if (n > 1)
            swap(ans[0], ans[1]);
    }
    else {
        ll log_n = log2(n);
        ll highest = (1LL << log_n);
        map<ll, bool> mp;
        vector<ll> temp;
        temp.push_back(highest);
        mp[highest] = true;
        highest--;
        temp.push_back(highest);
        mp[highest] = true;
        temp.push_back(highest - 1);
        temp.push_back(1);
        mp[highest - 1] = mp[1] = true;
        for (ll i = n; i > 0; i--)
            if (!mp[i])
                temp.push_back(i);
        reverse(vf(temp));
        if(find_max(temp) != highest)
            swap(temp[0], temp[1]);
        ans = temp;
    }
    cout << find_max(ans) << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

/*
5 - 5
2 1 3 4 5
6 - 7
1 2 3 4 6 5
7 - 7
1 2 3 4 6 5 7
8 - 15
1 2 3 4 6 5 7 8
9 - 9
1 2 3 4 6 5 7 8 9
10 - 15
1 2 3 4 5 6 8 9 10 7


*/

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}