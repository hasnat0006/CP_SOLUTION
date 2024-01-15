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
    if (((n * (n + 1)) / 2) % n == 0)
    {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for (int i = 2; i <= n; i += 2)
    {
        ans.pb(i);
        ans.pb(i - 1);
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