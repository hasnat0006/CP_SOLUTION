#include <bits/stdc++.h>
#define int unsigned long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    int aa, bb, aa1, bb1, ans1, ans2;
    if (((a - x) + (b - y)) < n) {
        cout << x * y << endl;
        return;
    }
    // todo decreasing A first-->
    aa = a - min((a - x), n);
    bb = b - (n - min((a - x), n));
    ans1 = aa * bb;
    // todo decreasing B first-->
    bb1 = b - min((b - y), n);
    aa1 = a - (n - min((b - y), n));
    ans2 = aa1 * bb1;
    cout << min(ans1, ans2) << endl;
    // cout << endl;
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