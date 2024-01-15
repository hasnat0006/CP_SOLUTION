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
    // vector<int> freq(1000001);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        // freq[v[i]]++;
    }
    sort(v.begin(), v.end());
    // vector<pair<int, int>> ans;
    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;
    int pair = n / 2, c = 0;
    for (int i = 1; i < n; ++i)
    {
        int MOD = v[i] % v[0];
        // cout << "i-> " << i << endl;
        if (MOD != v[0])
        {
            // ans.push_back({v[i], v[i + 1]});
            cout << v[i] << " " << v[0] << endl;
            c++;
        }
        if (c == pair)
            break;
    }
    // for (auto it : ans)
    //     cout << it.first << " " << it.second << endl;
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