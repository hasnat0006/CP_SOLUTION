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
    string s;
    cin >> s;
    int x = (s[0] - 'a') + 1;
    // cout << x << endl;
    int ans = 0;
    ans += (x - 1) * 25;
    // cout << ans << endl;
    int t1 = (s[1] - 'a');
    int t2 = s[0];
    if (s[0] > s[1])
        ans += t1 + 1;
    else
        ans += t1;
    cout << ans << endl;
    // cout << endl;
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