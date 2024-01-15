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
    vector<int> v(n), final, diff;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
            final.pb(v[i - 1]);
    }
    final.pb(v[n - 1]);
    // for (auto it : final)
    //     cout << it << " ";
    // cout << endl;
    if (final.size() == 1)
    {
        cout << "-1\n";
        return;
    }
    int ans = INT_MAX;
    for (int i = 1; i < final.size(); i++)
        diff.pb(final[i] - final[0]);
    // for (auto it : diff)
    //     cout << it << " ";
    // cout << endl;
    int x = diff[0];
    int c = 0;
    while (c != diff.size())
    {
        for (int i = 0; i < diff.size(); i++)
        {
            if (diff[i] % x == 0)
                c++;
            else
            {
                c = 0;
                x--;
                break;
            }
            // cout << i << " -> " << c << endl;
        }
    }
    cout << x << endl;
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