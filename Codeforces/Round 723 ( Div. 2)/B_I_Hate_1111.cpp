#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n;
    cin >> n;
    bool f = false;
    while (n > 0)
    {
        if (n % 11 == 0 or n % 111 == 0)
        {
            f = true;
            break;
        }
        else
            n -= 111;
    }
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}