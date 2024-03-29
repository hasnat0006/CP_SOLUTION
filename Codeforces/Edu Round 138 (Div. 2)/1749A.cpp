#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int pos[m][2];
    for (int i = 0; i < m; i++)
        cin >> pos[i][0] >> pos[i][1];
    if (m < n)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}