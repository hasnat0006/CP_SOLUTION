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
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> v[i];
    bool f = false;
    vector<int> ans(n);
    ans[0] = v[0];
    ans[n - 1] = v[n - 2];
    for (int i = 0; i < n - 2; i++)
    {
        ans[i + 1] = min(v[i], v[i + 1]);
        // cout<<min(v[i], v[i + 1]);
    }
    for (auto it : ans)
        cout << it << " ";
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