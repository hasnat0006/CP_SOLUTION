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
    int low = 1, high = INT_MAX, ans = -1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int x = cnt_zero(mid);
        // cout << x << endl;
        if (n == x)
        {
            // cout<<"r"<<endl;
            ans = mid;
            high = mid - 1;
        }
        else if (n > x)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "impossible\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }

    return 0;
}