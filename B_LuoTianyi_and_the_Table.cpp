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
    int n, m;
    cin >> n >> m;
    int size = n * m;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int mn1 = v[0], mn2 = v[1], mx1 = v[(size)-1], mx2 = v[size - 2];
    if (n < m)
        swap(n, m);
    // cout << mn1 << " " << mn2 << " " << mx1 << " " << mx2 << endl;
    int x = (n - 1) * m * (mx1 - mn1) + (m - 1) * (mx1 - mn2);
    int y = (n - 1) * m * (mx1 - mn1) + (m - 1) * (mx2 - mn1);
    cout << max(x, y) << endl;
}

int32_t main()
{
    // fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}