//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|03|2024 20:44:32            !//
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
    vector<int> coin = {1, 3, 6, 10, 15};
    vector<int> ans;

    auto count = [&](int start, int num) {
        int sum = num;
        int cnt = 0;
        for (int i = start; i >= 0; i--) {
            cnt += sum / coin[i];
            sum %= coin[i];
        }
        return cnt;
    };

    for (int i = 4; i >= 0; i--) {
        ans.push_back(count(i, n));
    }

    for (int i = 0; i < 5; i++) {
        int temp = inf;
        if (n - coin[i] < 0) {
            continue;
        }
        if (n - coin[i] == 0) {
            ans.push_back(1);
            continue;
        }
        for (int j = 4; j >= 0; j--) {
            temp = min(temp, count(j, n - coin[i]) + 1ll);
        }
        ans.push_back(temp);
    }
    sort(vf(ans));
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    cout << ans[0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}