//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int binaryExponentiation(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power % 2 == 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return ans;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 and b == 0)
        cout << "1\n";
    else
        cout << binaryExponentiation(a, b) << endl;
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