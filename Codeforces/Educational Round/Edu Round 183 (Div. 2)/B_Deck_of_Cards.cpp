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
    dbg(n, k, s);
    if (n == k) {
        string ans(n, '-');
        cout << ans << '\n';
        return;
    }
    string ans(n, '+');
    dbg(ans);
    ll i = 0, j = n - 1, qi = 0, qj = n - 1, f = 0;
    for (int kid = 0; kid < k; kid++) {
        if (s[kid] == '0') {
            if (ans[i] == '?') {
                ans[qi + 1] = '?';
                qi++;
            }
            ans[i] = '-';
            i++;
        }
        else if (s[kid] == '1') {
            if (ans[j] == '?') {
                ans[qj - 1] = '?';
                qj--;
            }
            ans[j] = '-';
            j--;
        }
        else {
            dbg(f, qi, qj);
            if (f == 0) {
                qj = j, qi = i, f = 1;
                ans[i] = ans[j] = '?';
                continue;
            }
            ans[qj - 1] = '?';
            qj--;
            ans[qi + 1] = '?';
            qi++;
        }
        dbg(kid, ans, i, j);
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