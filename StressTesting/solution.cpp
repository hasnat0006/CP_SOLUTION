#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ll segSum = 0, ans = 0;
    for (int i = l; i <= r; i++)
        segSum += v[i], ans = segSum;
    dbg(segSum);

    auto findMin = [&](vector<ll> &a, int L, int R) {
        vector<ll> pre(n + 1, 0);
        sort(v.begin(), v.begin() + L);
        sort(v.begin() + R + 1, v.end());
        partial_sum(vf(v), pre.begin());
        dbg(pre);
        ll tempAns = segSum;
        for (int i = L; i <= R; i++) {
            for (int j = L - 1; j > 0; j--) {
                ll len = i - L + 1;
                ll curSum = pre[i] - pre[i - len];
                dbg(pre[i], pre[i - len]);
                ll changeSum = pre[j + len - 1] - pre[j - 1];
                dbg(i, j, len, curSum, changeSum);
                dbg(segSum - curSum + changeSum);
                tempAns = min(tempAns, segSum - curSum + changeSum);
            }
        }
        return tempAns;
    };
    ans = min(ans, findMin(v, l, r));
    reverse(v.begin() + 1, v.end());
    int L = n - (r - 1), R = n - (l - 1);
    dbg(L, R);
    ans = min(ans, findMin(v, L, R));
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