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
    int ans = 0, temp1 = 0, temp2 = 0;
    ans += a / 3;
    ans += b / 3;
    ans += ((a % 3) + (b % 3)) / 3;
    ans = min(ans, min(a, b));
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