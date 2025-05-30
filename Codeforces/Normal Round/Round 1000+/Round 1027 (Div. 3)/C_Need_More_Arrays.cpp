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
    vector<ll> arr(n);
    set<pair<ll, ll>> s;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert({arr[i], i});
    }
    ll left = 0, right = 1;
    while (right < n) {
        if (arr[left] + 1 < arr[right]) {
            auto it = s.upper_bound({arr[left], left});
            left = it->second;
            right++;
            continue;
        }
        else {
            s.erase({arr[right], right});
            right++;
        }
    }
    cout << s.size() << endl;
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