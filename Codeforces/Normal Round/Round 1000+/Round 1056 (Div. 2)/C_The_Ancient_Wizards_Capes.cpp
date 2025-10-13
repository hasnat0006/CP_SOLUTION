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

const ll mod = 676767677;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (n == 1) {
        cout << 2 << '\n';
        return;
    }

    auto isValid = [&](string &ori) {
        vector<ll> left(n, 0), right(n, 0);
        left[n - 1] = (ori[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--) {
            left[i] = left[i + 1] + (ori[i] == '1');
        }
        right[0] = (ori[0] == '0');
        for (int i = 1; i < n; i++) {
            right[i] = right[i - 1] + (ori[i] == '0');
        }
        for (int i = 0; i < n; i++) {
            ll cnt = (i > 0 ? right[i - 1] : 0);
            cnt += (i != n - 1 ? left[i + 1] : 0);
            cnt++;
            if (cnt != v[i])
                return false;
        }
        return true;
    };
    string s(n, '?');
    ll cntEqual = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1])
            cntEqual++;
        else if (v[i] > v[i - 1]) {
            if (s[i - 1] == '1') {
                cout << 0 << '\n';
                return;
            }
            s[i] = s[i - 1] = '0';
        }
        else {
            if (s[i - 1] == '0') {
                cout << 0 << '\n';
                return;
            }
            s[i] = s[i - 1] = '1';
        }
    }

    if (cntEqual == n) {
        if (n % 2) {
            if ((n + 1) / 2 == v[0])
                cout << 2 << '\n';
            else
                cout << 0 << '\n';
        }
        else {
            if (v[0] == (n / 2) or v[0] == (n / 2) + 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        return;
    }
    dbg(s);

    for (int i = 1; i < n; i++) {
        if (s[i] == '?' and s[i - 1] != '?') {
            s[i] = (s[i - 1] == '1' ? '0' : '1');
        }
    }
    dbg(s);

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '?' and s[i + 1] != '?') {
            s[i] = (s[i + 1] == '1' ? '0' : '1');
        }
    }
    dbg(s);

    if (isValid(s))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    dbg(s);
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