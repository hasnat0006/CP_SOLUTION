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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);

    auto cmp = [](pair<ll, ll> a, pair<ll, ll> b) {
        return (a.first - a.second) < (b.first - b.second);
    };

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pq.push({v[i], 0});
    }
    
    dbg(pq);

    auto findCount = [&](ll highest, ll secondHighest) {
        ll l = 1, h = (highest / a) + (highest % a != 0);
        while (l < h) {
            ll mid = (l + h) / 2;
            ll h1 = highest - mid * a;
            ll h2 = secondHighest - mid * b;
            if (h2 > h1)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    };

    ll ans = 0, c = 0;

    auto reduce = [&]() {
        while (pq.size()) {
            auto [highest, f] = pq.top();
            highest -= ((c - f) * b);
            if (highest > 0)
                return;
            else
                pq.pop();
        }
    };

    while (pq.size()) {
        dbg(pq);
        reduce();
        if (pq.empty())
            break;
        auto [highest, f] = pq.top();
        highest -= ((c - f) * b);
        pq.pop();
        reduce();
        if (pq.size()) {
            auto [secondHighest, f2] = pq.top();
            pq.pop();
            secondHighest -= ((c - f2) * b);
            dbg(c, highest, secondHighest);
            ll count = findCount(highest, secondHighest);
            ans += count;
            highest -= a * count;
            secondHighest -= b * count;
            dbg(count, highest, secondHighest);
            if (highest > 0)
                pq.push({highest, f + 1});
            if (secondHighest > 0)
                pq.push({secondHighest, f2 + 1});
        }
        else {
            ans += (highest / a) + (highest % a != 0);
        }
        c++;
    }
    cout << ans << '\n';
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