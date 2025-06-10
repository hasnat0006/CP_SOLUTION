#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    vector<ll> cost1(n), cost2(n);
    ll prevMax = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            cost1[i] = cost[i];
            prevMax = 0;
        }
        else
            prevMax = max(prevMax, cost[i]);
        cost2[i] = prevMax;
    }
    ll ans = *max_element(vf(cost1));
    auto isOK = [&](ll mid) {
        ll move = 0, f = 0, cur_cost = mid;
        for (int i = 0; i < n; i++) {
            if (cost1[i] > mid and f == 0) {
                f = 1, move++;
            }
            else if (cost1[i] > mid and f) {
                if (cost2[i - 1] > mid)
                    move++;
                else
                    cur_cost = max(cur_cost, cost2[i - 1]);
            }
            else {
                if(cost2[i - 1] <= mid)
                    continue;
                cur_cost = max(cur_cost, cost1[i]);
                f = 0;
            }
        }
        if (move <= k) {
            // dbg(mid, ans, move, k, cur_cost);
            ans = min(ans, cur_cost);
            return true;
        }
        return false;
    };

    ll low = 0, high = *max_element(vf(cost1));
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (isOK(mid)) {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << '\n';
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