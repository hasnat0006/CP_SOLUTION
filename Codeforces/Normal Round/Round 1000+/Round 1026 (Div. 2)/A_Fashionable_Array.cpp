#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> even, odd;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    sort(vf(even));
    sort(vf(odd));
    auto findAns = [&](vector<ll> &a, vector<ll> &b) {
        ll ans = 0;
        if (a.empty() || b.empty())
            return 0ll;
        auto id = upper_bound(vf(b), a[0]);
        ll cnt = id - b.begin();
        auto id2 = lower_bound(vf(b), a.back());
        ll cnt2 = b.end() - id2;
        return cnt + cnt2;
    };
    cout << min(findAns(even, odd), findAns(odd, even)) << "\n";
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