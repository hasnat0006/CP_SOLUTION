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
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '0')
        reverse(vf(s));

    ll i = n - 1;
    while ((i >= 0 and s[i] == '0' and i - 1 >= 0 and s[i - 1] == '1' and
            i - 2 >= 0 and s[i - 2] == '0') or
           (i >= 0 and s[i] == '0' and i - 1 >= 0 and s[i - 1] == '0')) {
        s.pop_back();
        s.pop_back();
        i -= 2;
    }
    if (s.size() and s.back() == '0')
        s.pop_back();
    reverse(vf(s));

    i = s.size() - 1;
    while ((i >= 0 and s[i] == '0' and i - 1 >= 0 and s[i - 1] == '1' and
            i - 2 >= 0 and s[i - 2] == '0') or
           (i >= 0 and s[i] == '0' and i - 1 >= 0 and s[i - 1] == '0')) {
        s.pop_back();
        s.pop_back();
        i -= 2;
    }

    if (s.size() and s.back() == '0')
        s.pop_back();
    reverse(vf(s));

    dbg(s);
    n = s.size();
    ll zero = 0, one = 0, totalZero = 0, nextZ = n;
    i = n - 1;
    vector<ll> leftRight(n);  // l = 1, right = 2;
    while (i >= 0) {
        if (s[i] == '0') {
            dbg(i, nextZ);
            if (nextZ < n) {
                if (leftRight[nextZ] == 1)
                    leftRight[i] = 2;
                else
                    leftRight[i] = 1;
            }
            else
                leftRight[i] = 1;
            nextZ = i;
        }
        i--;
    }
    ll right = 0;
    for (int i = 0; i < n; i++) {
        dbg(i, right, one);
        if (s[i] == '1')
            one++;
        if (leftRight[i] == 2) {
            right = 1;
            one = 0;
        }
        if (leftRight[i] == 1) {
            if (one > 0 and i + 1 < n and leftRight[i + 1] != 0)
                leftRight[i] = 2;
            else if (one > 1) {
                dbg("i", i);
                cout << "NO\n";
                return;
            }
            right = 0;
        }
        dbg(i, right, one);
    }
    cout << "YES\n";
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