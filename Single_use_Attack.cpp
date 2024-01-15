#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int h, x, y;
    cin >> h >> x >> y;
    int hh = h;
    int c1 = 0, c2 = 0;
    int c = 0;
    while (h > 0)
    {
        if (c == 0)
        {
            h -= y;
            c++;
            c1++;
        }
        else
        {
            h -= x;
            c1++;
        }
    }
    h = hh;
    while (h > 0)
    {
        if (h - y <= 0)
        {
            h -= y;
            c++;
            c2++;
        }
        else
        {
            h -= x;
            c2++;
        }
    }
    // cout << c1 << " " << c2 << endl;
    cout << min(c1, c2) << endl;
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