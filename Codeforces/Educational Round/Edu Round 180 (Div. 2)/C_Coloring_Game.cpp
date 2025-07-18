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
    vector<int> a(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans  = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            ll sum = v[i] + v[j];
            ll id = lower_bound(vf(v), sum) - v.begin() - 1;
            ll low = j + 1, high = id;
            while(low <= high) {
                ll mid = (low + high) / 2;
                if(sum + v[mid] <= v.back()) 
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            ans += max(0LL, id - low + 1);
        } 
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