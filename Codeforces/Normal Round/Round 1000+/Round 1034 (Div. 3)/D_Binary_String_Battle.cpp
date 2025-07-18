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
    vector<ll> pre(n), suf(n);
    pre[0] = (s[0] == '0');
    ll one = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1')
            one++;
        if (s[i] == '0')
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = 0;
    }
    suf[n - 1] = (s[n - 1] == '0');
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '0')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = 0;
    }
    dbg(pre);
    dbg(suf);
    ll cnt = 0;
    if (one <= k) {
        cout << "Alice\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ll j = i;
            while (j < n and s[j] == '1') {
                dbg(i, j, cnt);
                ll sum = (i > 0 ? pre[i - 1] : 0);
                sum += (j < n - 1 ? suf[i + 1] : 0);
                sum += (j - i + 1);
                if (sum < k) {
                    cnt++;
                    j++;
                }
                else
                    break;
                dbg(cnt);
            }
            i = j;
            // cnt += pre[i];
        }
    }
    if (cnt >= k)
        cout << "Alice" << '\n';
    else
        cout << "Bob" << '\n';
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