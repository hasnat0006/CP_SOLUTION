#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = ((x2 - x1) * (y2 - y1)) + 1;
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}