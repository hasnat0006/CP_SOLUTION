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
    string a, b;
    cin >> a >> b;
    int caa = 0, cab = 0, ans = 0;
    for (int i = 0; a[i]; i++)
        if (a[i] == 'a')
            caa++;
    for (int i = 0; b[i]; i++)
        if (b[i] == 'a')
            cab++;
    // cout << cab << endl;
    if (cab == 1 and b.length() == 1)
        ans = 1;
    else if (cab >= 1)
        ans = -1;
    else if (cab == 0)
    {
        ans = 1;
        for (int i = 0; i < a.length(); i++)
            ans *= 2;
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