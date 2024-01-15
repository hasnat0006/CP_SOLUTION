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
    int n, q, x;
    cin >> n >> q;
    vector<int> v(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + v[i];
    // for (auto it : pre)
    //     cout << it << " ";
    // cout << endl;
    while (q--)
    {
        int c = 0, sum = 0;
        cin >> x;
        auto ans = lower_bound(pre.begin(), pre.end(), x);
        // cout << pre[ans] << endl;
        if (ans == pre.end())
            sum = -1;
        else
            sum = ans - pre.begin() + 1;
        cout << sum << endl;
            //  << endl;
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