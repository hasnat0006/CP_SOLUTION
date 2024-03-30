//!................  CG o nai CP o nai :)  ................!//
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n), pre;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    if (v[0] > 1) {
        cout << "NO\n";
        return;
    }
    pre.pb(v[0]);
    for (int i = 1; i < n; i++) {
        pre.pb((pre[i - 1] + v[i]));
    }
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] < v[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}