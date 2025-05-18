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
    vector<ll> a(n);
    if(x < n) {
        a[n - 1] = x;
        ll last = 0;
        for(int i = 0; i < x; i++) {
            a[i] = last++;
        }
        for(int i = x; i < n - 1; i++) {
            if(last == x)
                last++;
            a[i] = last++;
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            a[i] = i;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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