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
    set<ll> s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    ll c = 0;
    while (!s.empty()) {
        ll x = *s.begin();
        s.erase(s.begin());
        c++;
        if (s.size()) {
            ll need = (x % 4);
            ll f = 0;
            for (int i = 3; i < n; i += 4) {
                dbg(x, i, i - need);
                if (s.find(i - need) != s.end()) {
                    auto it = s.find(i - need);
                    c++;
                    s.erase(it);
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << "Alice" << '\n';
                return;
            }
        }
        else {
            cout << "Alice" << '\n';
            return;
        }
        dbg(s);
    }
    if (c % 2)
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