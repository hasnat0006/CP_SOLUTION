#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int gcd_of_xy = gcd(x, y);
    //! cout<<gcd_of_xy<<endl;
    x /= gcd_of_xy;
    y /= gcd_of_xy;
    cout<<min(a/x,b/y)<<endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}