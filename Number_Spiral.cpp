#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int x, ans, y;
    cin >> x >> y;
    int mx = max(x, y);
    if (mx % 2 == 0)
    {
        if (y == 1)
            ans = mx * mx;
        else if (x == mx)
            ans = (mx * mx) - y + 1;
        else
        {
            int temp = (mx * mx) - mx + 1;
            ans = temp - (mx - x);
        }
    }
    else
    {
        if (x == 1)
            ans = mx * mx;
        else if (y == mx)
            ans = (mx * mx) - x + 1;
        else
        {
            int temp = (mx * mx) - mx + 1;
            ans = temp - (mx - y);
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}