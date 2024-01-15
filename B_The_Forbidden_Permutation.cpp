#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    int p[n + 1];
    int pos[n + 1];
    int a[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[i] = i;
    }
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    int ans = INT_MAX, move = 0, x, y, choice;
    for (int i = 1; i < m; i++)
    {
        if ((pos[a[i]] < pos[a[i + 1]]) and (d >= pos[a[i + 1]]))
        {
            x = (pos[a[i + 1]] - pos[a[i]]);
            if (d < n - 1)
                move = d + 1 - (pos[a[i + 1]] - pos[a[i]]);
            choice = min(x, move);
        }
        else 
        {
            ans=0;
            break;
        }
        ans = min(ans, choice);
    }
    // cout << "8";
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