#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, ekbar = 0;
    bool f = true;
    cin >> n;
    vector<int> v(n), final;
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    if (v[0] == 1)
        final.push_back(v[0]);
    for (int i = 0; i < n; i++)
        if (v[i] != 1)
            final.push_back(v[i]);
    // for (int i = 0; i < final.size(); i++)
    //     cout << final[i] << " ";
    // cout << endl;
    int c = 1;
    for (int i = 0; i < final.size(); i++)
    {
        // cout <<i << " C " << c << endl;
        if (final[i] < (c))
            continue;
        else if (final[i] == c)
            c++;
        else if (final[i] != c)
        {
            int x = (final[i] - (c));
            ans += x;
            final[i] = c;
            c++;
            // cout<<x<<endl;
        }
        // cout << i << " " << c<<" "<< ans << endl;
    }
    // for (int i = 0; i < final.size(); i++)
        // cout << final[i] << " ";
    // cout << endl;
    // if (final[0] == 1 and final[final.size() - 1] == final.size())
        cout << ans << endl;
    // else
        // cout << ans + 1 << endl;
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