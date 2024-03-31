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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int x = 1, y = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            x++;
        }
        else
            break;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == b[i])
        {
            y--;
        }
        else
            break;
    }
    // cout << x << " " << y << endl;
    for (int i = x - 1; i > 0; i--)
    {
        if (b[i] >= b[i - 1])
            x--;
        else
            break;
    }
    for (int i = y - 1; i < n - 1; i++)
    {
        if (b[i] <= b[i + 1])
            y++;
        else
            break;
    }
    cout << x << " " << y << endl;
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