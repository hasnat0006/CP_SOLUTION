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

const ll N = 2e6 + 5;
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
    ll n = s.size();
    s += s;
    Hashing h(s);

    auto LCP = [&](ll i, ll j, ll x, ll y) {  // 1 base index
        // dbg(i, j, x, y);
        auto isOK = [&](ll mid) {
            if (mid == 0)
                return true;
            // dbg(mid, i, i + mid - 1, x, x + mid - 1);
            return h.get_hash(i, i + mid - 1) == h.get_hash(x, x + mid - 1);
        };

        ll low = 0, high = min(j - i + 1, y - x + 1), ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (isOK(mid))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    };

    auto compare = [&](ll i, ll j, ll x, ll y) {  // 0 based
        // dbg(i, j, x, y);
        ll lcp = LCP(i + 1, j + 1, x + 1, y + 1);
        ll len1 = j - i + 1, len2 = y - x + 1;
        if (len1 == len2 and len1 == lcp)
            return 0;  // both the string are equal
        if (len1 == lcp)
            return 1;  // string s[i...j] is smaller than s[x...y]
        if (len2 == lcp)
            return 2;  // string s[x...y] is smaller than s[i...j]
        if (s[i + lcp] < s[x + lcp])
            return 1;  // string s[i...j] is smaller than s[x...y]
        else
            return 2;  // string s[x...y] is smaller than s[i...j]
    };

    ll ansL = 0, ansR = n - 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (compare(i, i + n - 1, ansL, ansR) == 1)
            cnt++;
    }
    cout << ++cnt << endl;
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