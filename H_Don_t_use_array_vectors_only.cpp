#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, t1, a, b, q;
    cin >> n >> q;
    vector<int> v[n], temp;
    vector<vector<int>> ans;
    while (q--)
    {
        cin >> t1;
        if (t1 == 0)
        {
            cin >> a >> b;
            v[a].push_back(b);
            // v[a]+=temp;
        }
        else if (t1 == 2)
        {
            cin >> a;
            v[a].clear();
        }
        else if (t1 == 1)
        {
            cin >> a;
            // for(int i=0; i<v[a].size(); i++)
            // ans[c].push_back(v[a][i]);
            ans.push_back(v[a]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    int tt = 1;
    // cin >> t;
    while (tt--)
        solve();
    return 0;
}