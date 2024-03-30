//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), dif;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dif.pb(abs(v[i] - (i + 1)));
    }
    int ans = 0;
    for (int i = 0; i < dif.size(); i++)
        ans = __gcd(ans, dif[i]);
    cout << ans << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}