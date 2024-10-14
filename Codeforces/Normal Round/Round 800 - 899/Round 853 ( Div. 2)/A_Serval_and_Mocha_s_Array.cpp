#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    bool f = true;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // sort(v.begin(), v.end());
    int x = 99999999;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            x = min(x, __gcd(v[i], v[j]));
            // cout << x << endl;
        }
    }
    if (x <= 2)
        cout << "Yes\n";
    else
        cout << "No\n";
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