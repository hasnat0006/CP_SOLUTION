#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    int n = 2 * (x - y - 1) + 2;
    cout << n << endl;
    vector<int> v;
    for (int i = y; i < x; i++)
        v.pb(i);
    for (int i = x; i > y; i--)
        v.pb(i);
    for (auto p : v)
        cout << p << " ";
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