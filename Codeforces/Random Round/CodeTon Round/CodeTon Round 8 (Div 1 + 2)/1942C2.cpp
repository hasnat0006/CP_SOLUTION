//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|03|2024 22:24:48            !//
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

int SUM(int &y, vector<int> &odd) {
    int ans = 0;
    for (int s : odd) {
        if (y < s / 2) {
            ans += 2 * y;
            y = 0;
            break;
        }
        ans += s;
        y -= s / 2;
    }
    return ans;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
        cin >> v[i];
    sort(vf(v));
    int ans = x - 2;
    set<int> point(vf(v));
    for (auto i : point) {
        int left = i;
        int mid = ((i + 1) % n) == 0 ? n : (i + 1) % n;
        int right = ((i + 2) % n) == 0 ? n : (i + 2) % n;
        if (point.find(mid) == point.end() and
            point.find(right) != point.end()) {
            ans++;
        }
    }
    vector<int> odd, even;
    for (int i = 0; i < x; i++) {
        int next = (i == x - 1) ? n + v[0] : v[i + 1];
        int extra = next - v[i] - 1;
        if (extra % 2 and extra > 1)
            odd.push_back(extra);
        else if (extra % 2 == 0 and extra > 0)
            even.push_back(extra);
        dbg(v[i], next, extra);
    }
    sort(vf(odd));
    sort(vf(even));
    auto FUNCTION = [&](vector<int> &x) {
        for (int s : x) {
            if (y < s / 2) {
                ans += 2 * y;
                y = 0;
                break;
            }
            ans += s;
            y -= s / 2;
        }
        return;
    };
    FUNCTION(odd), FUNCTION(even);
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