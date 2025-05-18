#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll possible = -1;
    for(int i = 0; i < n; i++) {
        if(b[i] != -1) {
            if(possible != (a[i] + b[i]) and possible != -1) {
                cout << 0 << endl;
                return;
            }
            else 
                possible = a[i] + b[i];
        }
    }
    if(possible != -1) {
        for(int i = 0; i < n; i++) {
            if(b[i] == -1) {
                if(possible - a[i] > x or possible - a[i] < 0) {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
        return;
    }
    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());
    ll ans = x - (mx - mn) + 1;
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