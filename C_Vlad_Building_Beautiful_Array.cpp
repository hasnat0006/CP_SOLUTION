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
    vector<int> v(n);
    int mn = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mn = min(mn, v[i]);
        if (!(v[i] % 2))
            cnt++;
    }
    if (mn % 2 or cnt == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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