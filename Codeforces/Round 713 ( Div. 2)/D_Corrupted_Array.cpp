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
    int nn = n + 2;
    vector<int> v(nn);
    vector<int> pre(nn);
    cin >> v[0];
    for (int i = 1; i < nn; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    pre[0] = v[0];
    for (int i = 1; i < nn; i++)
        pre[i] = v[i] + pre[i - 1];
    // for (auto it : pre)
    //     cout << it << " ";
    // cout << endl;
    bool f = 0;
    if (pre[n - 1] == v[n])
    {
        f = 1;
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n + 1; i++)
    {
        if ((pre[n] - v[i]) == v[n + 1])
        {
            f = 1;
            v.erase(v.begin() + i);
            break;
        }
    }
    if (!f)
        cout << "-1\n";
    else
    {
        v.pop_back();
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
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