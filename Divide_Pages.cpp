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
    vector<int> v(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (even == n)
        cout << "YES\n";
    else if (odd == n and n == even)
        cout << "YES\n";
    else if (odd % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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