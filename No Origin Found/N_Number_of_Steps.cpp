#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

// smallest prime factor of a number.
ll factor(ll n) {
    if (n % 2 == 0)
        return 2;
    for (ll a = 3; a * a <= n; a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    ll n;
    cin >> n;
    ll N = 1e6 + 5;
    vector<ll> here(N), cnt(N);
    set<pair<ll, ll>> idVal, valId;
    for (int i = 0; i < n; i++) {
        ll x, f = 0;
        cin >> x;
        if (here[x]) {
            f = 1;
            here[x] = 0;
        }
        else
            here[x] = 1;
        while (x > 1) {
            ll r = factor(x);
            while (x % r == 0)
                x /= r;
            ll current = cnt[r] + (f == 1 ? -1 : 1);
            if (idVal.find({r, cnt[r]}) != idVal.end()) {
                idVal.erase(idVal.find({r, cnt[r]}));
                valId.erase(valId.find({cnt[r], r}));
            }
            idVal.insert({r, current});
            valId.insert({current, r});
            cnt[r] = current;
        }
        cout << (*valId.rbegin()).first << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}