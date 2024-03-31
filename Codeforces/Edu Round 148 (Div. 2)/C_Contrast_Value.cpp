//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> v;
    int cont = 0;
    for (int i = 0; i < n; i++)
        cin >> x, v.pb(x);
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0 or i == v.size() - 1 or
            (v[i - 1] < v[i]) == (v[i] > v[i + 1]))
            ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}