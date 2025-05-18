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
    int arr[n + 1][n + 1];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> arr[i + 1][j + 1];
        }
    }
    vector<ll> ans(2 * n + 1);
    set<ll> s;
    for(int i = 1; i <= n; i++) {
        ans[i + 1] = arr[i][1];
        s.insert(arr[i][1]);
    }
    for(int i = 2; i <= n; i++) {
        ans[i + n] = arr[n][i];
        s.insert(arr[n][i]);
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(s.find(i) == s.end()) {
            ans[1] = i;
            break;
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << " ";
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