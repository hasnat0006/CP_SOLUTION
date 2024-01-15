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
    if (a[0] != b[0])
    {
        cout << "NO\n";
        return;
    }
    bool f = true;
    int plus = 0, minus = 0;
    for (int i = 0; i < n; i++)
    {
        if ((b[i] - a[i] > 0 and plus == 0) or (b[i] - a[i] < 0 and minus == 0))
        {
            f = false;
            break;
        }
        else
        {
            if (a[i] == 1)
                plus++;
            else if (a[i] == -1)
                minus++;
        }
        // cout << "plus-> " << plus << "  minus-> " << minus << endl;
    }
    // cout << "plus-> " << plus << "  minus-> " << minus << endl;
    if (!f)
        cout << "NO\n";
    else
        cout << "YES\n";
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