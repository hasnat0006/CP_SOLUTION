//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|06|2025 23:10:36            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll binaryExp(ll base, ll power, ll MOD = mod) {
    ll res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}

const ll N = 2e5 + 5;
const ll MOD1 = 127657753, MOD2 = 987654319;
const ll p1 = 137, p2 = 277;
ll ip1, ip2;
pair<ll, ll> pw[N], ipw[N];

void prec() {
    pw[0] = {1, 1};
    for (ll i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = binaryExp(p1, MOD1 - 2, MOD1);
    ip2 = binaryExp(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for (ll i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}
struct Hashing {
    ll n;
    string s;                 // 0 - indexed
    vector<pair<ll, ll>> hs;  // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (ll i = 0; i < n; i++) {
            pair<ll, ll> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<ll, ll> get_hash(ll l, ll r) {
        // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<ll, ll> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL *
                    ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL *
                     ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<ll, ll> get_hash() { return get_hash(1, n); }
};

void solve() {
    string s;
    cin >> s;
    prec();
    Hashing h(s);
    ll n = s.size();

    auto isOK = [&](ll len) {
        if (len == 0)
            return true;
        set<pair<ll, ll>> st;
        for (ll i = 1; i + len - 1 <= n; i++) {
            st.insert(h.get_hash(i, i + len - 1));
        }
        return st.size() < n - len + 1;
    };

    ll low = 0, high = n, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (isOK(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (ans == 0) {
        cout << "-1\n";
        return;
    }
    set<pair<ll, ll>> st;
    for (ll i = 1; i + ans - 1 <= n; i++) {
        if (st.count(h.get_hash(i, i + ans - 1))) {
            cout << s.substr(i - 1, ans) << '\n';
            return;
        }
        st.insert(h.get_hash(i, i + ans - 1));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}