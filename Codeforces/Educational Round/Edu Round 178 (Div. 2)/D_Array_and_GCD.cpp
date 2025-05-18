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

vector<ll> primes;

vector<ll> sieve(ll N, ll Q = 17, ll L = 1 << 15) {
    ll rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
    struct P {
        P(ll p) : p(p) {}
        ll p;
        ll pos[8];
    };
    auto approx_prime_count = [](ll N) {
        return N > 60184 ? N / (log(N) - 1.1)
                         : max(1., N / (log(N) - 1.11)) + 1;
    };
    ll v = sqrt(N), vv = sqrt(v);
    vector<bool> isp(v + 1, true);
    for (ll i = 2; i <= vv; ++i) {
        if (isp[i]) {
            for (ll j = i * i; j <= v; j += i)
                isp[j] = false;
        }
    }
    ll rsize = approx_prime_count(N + 30);
    vector<ll> primes = {2, 3, 5};
    ll ps = 3;
    primes.resize(rsize);
    vector<P> sprimes;
    size_t pbeg = 0;
    ll prod = 1;
    for (ll p = 7; p <= v; ++p) {
        if (!isp[p])
            continue;
        if (p <= Q) {
            prod *= p;
            ++pbeg;
            primes[ps++] = p;
        }
        auto pp = P(p);
        for (ll t = 0; t < 8; ++t) {
            ll j = (p <= Q) ? p : p * p;
            while (j % 30 != rs[t])
                j += p << 1;
            pp.pos[t] = j / 30;
        }
        sprimes.push_back(pp);
    }
    vector<unsigned char> pre(prod, 0xFF);
    for (size_t pi = 0; pi < pbeg; ++pi) {
        auto pp = sprimes[pi];
        ll p = pp.p;
        for (ll t = 0; t < 8; ++t) {
            unsigned char m = ~(1 << t);
            for (ll i = pp.pos[t]; i < prod; i += p)
                pre[i] &= m;
        }
    }
    ll bs = (L + prod - 1) / prod * prod;
    vector<unsigned char> block(bs);
    unsigned char* pb = block.data();
    ll M = (N + 29) / 30;
    for (ll s = 0; s < M; s += bs, pb -= bs) {
        ll f = min(M, s + bs);
        for (ll i = s; i < f; i += prod) {
            copy(pre.begin(), pre.end(), pb + i);
        }
        if (s == 0)
            pb[0] &= 0xFE;
        for (size_t pi = pbeg; pi < sprimes.size(); ++pi) {
            auto& pp = sprimes[pi];
            ll p = pp.p;
            for (ll t = 0; t < 8; ++t) {
                ll i = pp.pos[t];
                unsigned char m = ~(1 << t);
                for (; i < f; i += p)
                    pb[i] &= m;
                pp.pos[t] = i;
            }
        }
        for (ll i = s; i < f; ++i) {
            for (ll m = pb[i]; m > 0; m &= m - 1) {
                primes[ps++] = i * 30 + rs[__builtin_ctz(m)];
            }
        }
    }
    assert(ps <= rsize);
    while (ps > 0 && primes[ps - 1] > N)
        --ps;
    primes.resize(ps);
    return primes;
}

void solve() {
    ll n;
    cin >> n;
    set<pair<ll, ll>> s;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert({x, i});
    }
    ll need = n, coin = 0, ans = 0;
    for (int i = 0; (i < need and !s.empty()); i++) {
        auto last = s.rbegin();
        if (last->first >= primes[i]) {
            dbg(last->first, last->second);
            coin += last->first - primes[i];
            s.erase(s.find({last->first, last->second}));
        }
        else {
            if (last->first + coin >= primes[i]) {
                coin -= (primes[i] - last->first);
                s.erase(s.find({last->first, last->second}));
            }
            else {
                ans++;
                need--;
                i--;
            }
        }
        dbg(i, need, s, coin, ans);
    }
    cout << ans << "\n";
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    primes = sieve(1e9 + 2);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}