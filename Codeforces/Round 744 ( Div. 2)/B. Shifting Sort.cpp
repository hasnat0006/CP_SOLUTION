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
    int n, x;
    cin >> n;
    map<int, int> m;
    vector<pair<int, int>> ans1;
    vector<int> v, v1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        v.pb(x);
        v1.pb(x);
        m[x] = i;
    }
    sort(v.begin(), v.end());
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int id;
        for (int j = 0; j < v1.size(); j++)
        {
            if (v[i] == v1[j])
            {
                id = j;
                break;
            }
        }
        if (i == id)
        {
            v1.pop_back();
            continue;
        }
        else
        {
            ans1.pb({id + 1, i + 1});
            vector<int> temp;
            for (int k = 0; k < v1.size(); k++)
            {
                if (k == id)
                    continue;
                temp.pb(v1[k]);
            }
            v1 = temp;
        }
    }
    cout << ans1.size() << endl;
    for (auto it : ans1)
        cout << it.first << " " << it.second << " 1" << endl;
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