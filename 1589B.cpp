#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void swap(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
}
void solve()
{
    int n, m, ans = 0, temp = 0;
    cin >> n >> m;
    if (m > n)
        swap(&n, &m);
    if (n == 1 or n == 2)
    {
        ans += m / 3;
        if (m % 3 != 0)
            ans++;
        if (m > 1)
            ans *= n;
    }
    else if (n >= 3)
    {
        ans += (m * (n / 3));
        n %= 3;
        if (m > n)
            swap(&n, &m);
        ans += (m * (n / 3));
        n %= 3;
        if (m > n)
            swap(&n, &m);
        if (n % 3 != 0)
        {
            temp += m / 3;
            if (m % 3 != 0)
                temp++;
            if (m != 1)
                ans += temp * (n);
            else
                ans += temp;
        }
    }
    // cout << "N " << n << " M " << m << endl;
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