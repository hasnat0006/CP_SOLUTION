//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
int solve(int n, int m)
{
    if (n == m)
        return 1;
    if (n == 0)
        return 0;
    int t = n / 3;
    if (3 * t != n)
        return 0;
    if (t == m or 2 * t == m)
        return 1;
    int temp1 = solve(t, m);
    int temp2 = solve(2 * t, m);
    if (temp1 == 1 or temp2 == 1)
        return 1;
    return 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // if (m > n or n % 3 != 0)
    // {
    //     cout << "NO\n";
    //     return;
    // }
    // else if (m == n)
    // {
    //     cout << "YES\n";
    //     return;
    // }
    // while (n >= m)
    // {
    //     if (m == n or m * 3 == n)
    //     {
    //         cout << "YES\n";
    //         return;
    //     }
    //     if (m % 2 == 0)
    //         m = m + m / 2;
    //     else
    //         m = 3 * m;
    //     // cout << "m: " << m << endl;
    // }
    // cout << "NO\n";
    if (solve(n, m) == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}