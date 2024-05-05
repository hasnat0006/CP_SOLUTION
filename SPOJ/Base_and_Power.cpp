
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    double xa = (a * 1.0) * log10(x);
    double xb = (b * 1.0) * log10(y);
    // cout<<xa<<" "<<xb<<endl;
    if (xa == xb)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
