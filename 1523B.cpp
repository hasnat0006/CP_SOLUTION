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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> op;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i += 2)
    {
        if (v[i] == v[i + 1])
        {
            int x = 4;
            op.pb(2);
            op.pb(2);
            op.pb(1);
            op.pb(1);
            while (x--)
                vp.pb({i+1, i + 2});
        }
        else
        {
            int x = 2, y = 6;
            while (x--)
            {
                op.pb(1);
                op.pb(2);
                op.pb(1);
            }
            while (y--)
                vp.pb({i+1, i + 2});
        }
    }
    cout << op.size() << endl;
    for (int i = 0; i < op.size(); i++)
        cout << op[i] << " " << vp[i].first << " " << vp[i].second << endl;
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