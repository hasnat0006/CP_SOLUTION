#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int l, r;
    cin >> l >> r;
    vector<pair<int, int>> v;
    for (int i = 0; i < l; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int f1 = 0, f2 = 0;
    for (int i = 0; i < l; i++) {
        if (v[i].first == r)
            f1++;
        if (v[i].second == r)
            f2++;
    }
    // cout << f << endl;
    if (f1 > 0 and f2 > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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