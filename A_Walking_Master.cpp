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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b)
    {
        cout << "-1\n";
        return;
    }
    int move = d - b;
    a += move;
    if (a < c)
        cout << "-1\n";
    else
    {
        move += (a - c);
        cout << move << endl;
    }
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