#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, p;
    cin >> n;
    vector<int> v1(n + 1), v2(n + 1);
    for (int i = 1, j = n; i <= n, j > 0; i++, j--)
    {
        cin >> p;
        v1[p] = i;
        v2[p] = j;
    }
    int x = 0, y = 0;
    int q;
    cin >> q;
    while (q--)
    {
        int temp;
        cin >> temp;
        x += v1[temp];
        y += v2[temp];
        // cout << x << " " << y << endl;
    }
    cout << x << " " << y << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}