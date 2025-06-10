#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<ll> bc, ba, cb, ca;

    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;
        if (x == 'b') {
            if (y == 'c')
                bc.insert(i);
            else if (y == 'a')
                ba.insert(i);
        }
        else if (x == 'c') {
            if (y == 'b')
                cb.insert(i);
            else if (y == 'a')
                ca.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            continue;
        else if (s[i] == 'b') {
            if (!ba.empty()) {
                s[i] = 'a';
                ba.erase(ba.begin());
            }
            else if (!bc.empty() && !ca.empty()) {
                auto it1 = *bc.begin();
                auto it2 = ca.upper_bound(it1);
                if (it2 != ca.end()) {
                    s[i] = 'a';
                    bc.erase(bc.begin());
                    ca.erase(it2);
                }
            }
        }
        else {
            if (!ca.empty()) {
                s[i] = 'a';
                ca.erase(ca.begin());
            }
            else if (!cb.empty() && !ba.empty()) {
                auto it1 = *cb.begin();
                auto it2 = ba.upper_bound(it1);
                if (it2 != ba.end()) {
                    s[i] = 'a';
                    cb.erase(cb.begin());
                    ba.erase(it2);
                }
                else {
                    s[i] = 'b';
                    cb.erase(cb.begin());
                }
            }
            else if (!cb.empty()) {
                s[i] = 'b';
                cb.erase(cb.begin());
            }
        }
    }
    cout << s << '\n';
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