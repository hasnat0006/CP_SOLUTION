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

    auto query = [](vector<ll> &v) {
        ll n = v.size();
        cout << "? " << n;
        for (int i = 0; i < n; i++) {
            cout << " " << v[i];
        }
        cout << endl;
        ll x;
        cin >> x;
        return x;
    };

    vector<ll> v, ans(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        v.push_back(i);
        auto q = query(v);
        if (q != 0) {
            ans[i] = q;
            v.pop_back();
        }
    }
    v.clear();
    for (int i = 2 * n; i >= 1; i--) {
        v.push_back(i);
        if (!ans[i]) {
            auto q = query(v);
            if (q != 0) {
                ans[i] = q;
                v.pop_back();
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= 2 * n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}