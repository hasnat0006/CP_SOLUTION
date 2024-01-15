//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans;
    if (n % 2 == 1)
    {
        ans = ((n / 2) + 1) * b + (n / 2) * a;
    }
    else
    {
        ans = (n / 2) * b + (n / 2) * a;
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
        unsolve();
    return 0;
}