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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int ans = INT_MAX;
    int x = x2 + abs(x2 - x1);
    int y = y2;
    if (x < n)
        ans = min(abs(x - x2), ans);
    cout << ans << endl;
    x = x2 - abs(x2 - x1);
    if (x > 0)
        ans = min(abs(x - x2), ans);
    cout << ans << endl;
    x = x2;
    y = x1;
    ans = min(ans, abs(y - y2));
    cout << ans << endl;
    x = n - x1 + 1;
    y = x1;
    ans = min(abs(x - x2), abs(y - y2));
    cout << ans << endl;
    cout << "\n\n";
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