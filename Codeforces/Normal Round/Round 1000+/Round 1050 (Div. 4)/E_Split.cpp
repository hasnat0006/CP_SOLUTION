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
    map<ll, ll> mp;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    for(auto &[num, cnt] : mp) {
        if(cnt % k){
            cout << 0 << '\n';
            return;
        }
        cnt /= k;
    }

    ll ans = 0;
    map<ll, ll> c;
    for(int r = 0, l = 0; r >= l and r < n; r++) {
        c[v[r]]++;
        while(c[v[r]] > mp[v[r]]) {
            c[v[l]]--;
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

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