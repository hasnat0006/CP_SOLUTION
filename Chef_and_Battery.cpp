//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 50)
    {
        cout << "0\n";
        return;
    }
    int ans = 0;
    if (n < 50)
    {
        int x = 50 - n;
        if (x % 2 == 0)
            ans = x / 2;
        else
        {
            x += 3;
            ans = x / 2;
            ans++;
        }
    }
    else
    {
        int y = n - 50;
        if (y % 3 == 0)
            ans = y / 3;
        else
        {
            y += 2;
            if (y % 3 == 0)
            {
                ans = y / 3;
                ans++;
            }
            else
            {
                y += 2;
                ans = y / 3;
                ans += 2;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}