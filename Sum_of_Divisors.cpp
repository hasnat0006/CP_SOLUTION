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

int sumofDivisor(int n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            sum += (i + (n / i));
    cout << sum << endl;
    if (sqrt(n) * sqrt(n) == n)
        sum -= sqrt(n);
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    cout << sumofDivisor(n) << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}