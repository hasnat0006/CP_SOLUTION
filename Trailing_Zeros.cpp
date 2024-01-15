#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int cnt_zero(int n)
{
    int c = 0;
    while (n != 0)
    {
        c += n / 5;
        n /= 5;
    }
    return c;
}
void solve()
{
    int n;
    cin >> n;
    cout << cnt_zero(n) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}