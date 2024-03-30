//!..............CG o nai CP o nai :)................!//
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
    vector<int> v(n), ans1, ans2;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 0)
            pos++;
    }
    int pos_c = pos;
    neg = n - pos;
    int mn = min(pos, neg);
    int neg_c = neg;
    for (int i = 1; i <= pos; i++) {
        ans1.pb(i);
    }
    for (int i = 1; i <= neg; i++) {
        pos--;
        ans1.pb(pos);
    }
    for (int i = 1; i <= 2 * mn; i++) {
        if (i % 2 == 1)
            ans2.pb(1);
        else
            ans2.pb(0);
    }
    int x = 1;
    for (int i = ans2.size(); i < n; i++) {
        ans2.pb(x);
        x++;
    }
    for (auto it : ans1)
        cout << it << " ";
    cout << endl;
    for (auto it : ans2)
        cout << it << " ";
    cout << endl;
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