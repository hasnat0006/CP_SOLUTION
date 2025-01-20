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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    auto checkIsPer = [&](set<ll> &v) {
        ll val = 1;
        for (auto i : v)
            if (i != val++)
                return false;
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            ll val = 1, k = i;
            vector<ll> temp(n);
            while (k >= 0) {
                temp[k--] = val++;
            }
            k = i + 1;
            while (k < n) {
                temp[k++] = val++;
            }
            dbg(temp);
            for (int j = 0; j < n; j++) {
                if (s[j] == 's') {
                    set<ll> st;
                    for (int id = j; id < n; id++)
                        st.insert(temp[id]);
                    if (!checkIsPer(st)) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
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