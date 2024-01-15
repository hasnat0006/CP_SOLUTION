#include <bits/stdc++.h>
#define int long long
#define float double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int mx = 0;
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {
        int em;
        cin >> em;
        vector<int> temp(em);
        for (int j = 0; j < em; j++)
        {
            cin >> temp[j];
            if (temp[j] >= mx)
                mx = temp[j];
        }
        v[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        sort(v[i].rbegin(), v[i].rend());
    }
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (v[i][j] < mx)
            {
                cost += (mx - v[i][j]) * v[i].size();
            }
        }
    }
    cout << cost << endl;
    // cout<<mx<<endl;
}
int32_t main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}