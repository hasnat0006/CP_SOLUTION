//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
const int mod = 1000000007;
const float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int binaryExponetiation(int base, int power, int modulo)
{
    int ans = 1;
    while (power)
    {
        if (power % 2 == 1)
            ans = (ans * base) % modulo;
        base = (base * base) % modulo;
        power /= 2;
    }
    return ans;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << binaryExponetiation(a, binaryExponetiation(b, c, mod - 1), mod) << endl;
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