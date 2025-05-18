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
    vector<ll> ans;

    ll i = 1;
    while (i <= n) {
        ll div = n / i;
        ll next = (n / div) + 1;
        ans.push_back(div);
        i = next;
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
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