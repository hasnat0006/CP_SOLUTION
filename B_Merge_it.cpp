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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;
    int remind[3] = {0};
    int sum = 0, ans = 0, num = 0;
    for (int i = 0; i < n; i++)
        remind[(v[i] % 3)]++;
    ans += remind[0];
    ans += min(remind[1], remind[2]);
    int x = remind[1] - min(remind[1], remind[2]);
    if (x > 2)
        ans += x / 3;
    int y = remind[2] - min(remind[1], remind[2]);
    if (y > 2)
        ans += (y / 3);
    cout << ans << endl;
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