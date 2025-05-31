#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    function<void(vector<ll>)> gen = [&](vector<ll> v) {
        if(v.size() == k) {
            ll product = 1;
            for(int i = 1; i < k; i++) {
                product = max(product, v[i] * v[i - 1]);
            }
            if(product <= n) {
                cnt++;
            }
            return;
        }
        for(ll i = 1; i <= n; i++) {
            v.push_back(i);
            gen(v);
            v.pop_back();
        }
    };
    vector<ll> v;
    gen(v);
    cout << cnt << "\n";
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