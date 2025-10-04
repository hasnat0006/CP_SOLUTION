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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            v[i] = i + 1;
    }
    ll st = 0, done = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            ll c = v[i] - 1;
            if (st != i)
                v[st++] = c--;
            done++;
            while (st != i) {
                v[st] = done++;
                st++;
            }
            done = v[i];
            st = i + 1;
        }
    }
    ll c = n;
    if (st < n)
        v[st++] = c--;
    done++;
    while (st < n) {
        v[st] = done++;
        st++;
    }
    dbg(v);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' and v[i] == i + 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    for (auto i : v)
        cout << i << " ";
    cout << '\n';
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