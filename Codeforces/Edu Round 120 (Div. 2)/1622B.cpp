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
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    string s;
    cin >> s;
    map<int, int> ans;
    vector<int> t1, t0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            t0.pb(v[i]);
        else
            t1.pb(v[i]);
    }
    sort(t1.begin(), t1.end());
    sort(t0.begin(), t0.end());
    int c = 1;
    for (int i = 0; i < t0.size(); i++)
        ans[t0[i]] = c++;
    for (int i = 0; i < t1.size(); i++)
        ans[t1[i]] = c++;
    // for (auto it : ans)
    //     cout << it.first << " " << it.second << endl;
    for (int i = 0; i < n; i++)
        cout << ans[v[i]] << " ";
    cout << endl;
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