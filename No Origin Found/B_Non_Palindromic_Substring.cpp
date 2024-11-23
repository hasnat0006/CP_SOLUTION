//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|11|2024 00:49:10            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

ll binaryExp(ll base, ll power, ll MOD) {
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
    ip1 =    (p1, MOD1 - 2, MOD1);
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
    pair<ll, ll> get_hash(ll l, ll r) {  // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<ll, ll> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<ll, ll> get_hash() { return get_hash(1, n); }
};

void solve() {
    ll n, q;
    string s1;
    cin >> n >> q >> s1;
    Hashing actual(s1);
    string s2 = s1;
    reverse(vf(s2));
    Hashing rev(s2);
    vector<vector<ll>> count(n, vector<ll>(26, 0));

    for (int i = 0; i < n; i++) {
        count[i][s1[i] - 'a'] = 1 + (i > 0 ? count[i - 1][s1[i] - 'a'] : 0);
    }

    string evenString = "", oddString = "";

    for (ll i = 0; i < n; i++) {
        if (i % 2 == 0)
            evenString.push_back(s1[i]);
        else
            oddString.push_back(s1[i]);
    }

    vector<vector<ll>> evenOccur(n, vector<ll>(26, 0)),
        oddOccur(n, vector<ll>(26, 0));

    for (ll i = 0; i < evenString.size(); i++) {
        evenOccur[i][evenString[i] - 'a'] =
            1 + (i > 0 ? evenOccur[i - 1][evenString[i] - 'a'] : 0);
    }

    for (ll i = 0; i < oddString.size(); i++) {
        oddOccur[i][oddString[i] - 'a'] =
            1 + (i > 0 ? oddOccur[i - 1][oddString[i] - 'a'] : 0);
    }

    auto checkPalindrome = [&](ll l, ll r) {
        ll revl = n - r + 1;
        ll revr = n - l + 1;
        auto hash1 = actual.get_hash(l, r);
        auto hash2 = rev.get_hash(revl, revr);
        return hash1 == hash2;
    };

    auto checkAllSame = [&](ll l, ll r) {
        if (s1[l] != s1[r])
            return false;
        ll cnt =
            count[r][s1[r] - 'a'] - (l > 0 ? count[l - 1][s1[l] - 'a'] : 0);
        return cnt == (r - l + 1);
    };

    auto checkAllEvenSame = [&](ll l, ll r) {
        ll cnt = evenOccur[r][evenString[r] - 'a'] -
                 (l > 0 ? evenOccur[l - 1][evenString[l] - 'a'] : 0);
        return cnt == (r - l + 1);
    };

    auto checkAllOddSame = [&](ll l, ll r) {
        ll cnt = oddOccur[r][oddString[r] - 'a'] -
                 (l > 0 ? oddOccur[l - 1][oddString[l] - 'a'] : 0);
        return cnt == (r - l + 1);
    };

    auto sum = [](ll x) { return 1LL * x * (x + 1) / 2; };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (checkPalindrome(l, r)) {
            //! check all the char are same or not
            if (checkAllSame(l - 1, r - 1)) {
                cout << 0 << '\n';
            }
            else {
                //! is substring is like abababa ?
                ll len = r - l + 1;
                l--, r--;
                ll isEven = l % 2;
                if (isEven == 0) {
                    if (checkAllEvenSame((l / 2), (r / 2)) and
                        checkAllOddSame((l / 2), (r / 2) - 1))
                        cout << 2 * sum(len / 2) << '\n';
                    else
                        cout << sum(r - l) - 1 << '\n';
                }
                else {
                    if (checkAllOddSame((l / 2), (r / 2)) and
                        checkAllEvenSame((l / 2) + 1, (r / 2)))
                        cout << 2 * sum(len / 2) << '\n';
                    else
                        cout << sum(r - l) - 1 << '\n';
                }
            }
        }
        else {
            if (checkPalindrome(l, r - 1) and checkPalindrome(l + 1, r)) {
                ll len = (r - l + 1) / 2;
                cout << 2 * sum(len) << '\n';
            }
            else
                cout << sum(r - l + 1) - 1 << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    prec();
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}