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
    int a, b;
    cin >> a >> b;
    int ans, mn;
    a = abs(a), b = abs(b);
    mn = min(a, b);
    ans = mn * 2;
    int baki = (a + b) - (mn * 2);
    if (baki != 0)
        ans += (baki * 2) - 1;
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