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

class SEGMENT_TREE {
   public:
    string s;
    vector<pair<ll, ll>> seg, v;
    SEGMENT_TREE(ll n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! llially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(ll ti, ll low, ll high) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = MERGE(seg[2 * ti], seg[2 * ti + 1]);
    }

    pair<ll, ll> MERGE(pair<ll, ll> a, pair<ll, ll> b) {
        pair<ll, ll> p;
        p.first = (a.first + b.first) % MOD1;
        p.second = (a.second + b.second) % MOD2;
        return p;
    }

    //! llially: ti = 1, low = 1, high = n(number of elements in the array), (ql
    //! & qr) = user input in 1 based indexing;
    pair<ll, ll> find(ll ti, ll tl, ll tr, ll ql, ll qr) {
        if (tl > qr || tr < ql) {
            return {0, 0};
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        ll mid = (tl + tr) / 2;
        auto l = find(2 * ti, tl, mid, ql, qr);
        auto r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return MERGE(l, r);
    }
    //! llially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
    //! user input in 1 based indexing, val = updated value;
    void update(ll ti, ll tl, ll tr, ll id, ll val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti] = v[id];
            return;
        }
        ll mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = MERGE(seg[2 * ti], seg[2 * ti + 1]);
    }
    pair<ll, ll> get_hash(ll n, ll l, ll r) {
        auto p = find(1, 1, n, l, r);
        p.first = p.first * ipw[l - 1].first % MOD1;
        p.second = p.second * ipw[l - 1].second % MOD2;
        return p;
    }
    // use 1 based indexing for input and queries and update;
};

void solve() {
    prec();
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "." + s;
    SEGMENT_TREE S(n), R(n);

    auto cal = [&](ll i, ll j) {
        pair<ll, ll> p;
        p.first = (1LL * pw[i].first * s[j] % MOD1) % MOD1;
        p.second = (1LL * pw[i].second * s[j] % MOD2) % MOD2;
        return p;
    };

    for (int i = 1; i <= n; i++) {
        S.v[i] = cal(i - 1, i);
    }
    for (int i = n, j = 1; i > 0; i--, j++) {
        R.v[j] = cal(j - 1, i);
    }
    S.build(1, 1, n);
    R.build(1, 1, n);
    while (m--) {
        ll type;
        cin >> type;
        if (type == 2) {
            ll l, r;
            cin >> l >> r;
            auto p1 = S.get_hash(n, l, r);
            auto p2 = R.get_hash(n, n - r + 1, n - l + 1);
            cout << (p1 == p2 ? "YES" : "NO") << '\n';
        }
        else {
            ll id;
            char c;
            cin >> id >> c;
            s[id] = c;
            S.v[id] = cal(id - 1, id);
            R.v[n - id + 1] = cal(n - id, id);
            S.update(1, 1, n, id, c);
            R.update(1, 1, n, n - id + 1, c);
        }
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