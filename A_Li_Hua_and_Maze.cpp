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
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans1, ans2 ;
    if ((x1 == 1 && y1 == 1) or (x1 == n && y1 == 1) or (x1 == 1 && y1 == m) or (x1 == n and y1 == m))
        ans1 = 2;
    else if (x1 == 1 or y1 == 1 or x1 == n or y1 == m)
        ans1 = 3;
    else
        ans1 = 4;
    if ((x2 == 1 && y2 == 1) or (x2 == n && y2 == 1) or (x2 == 1 && y2 == m) or (x2 == n and y2 == m))
        ans2 = 2;
    else if (x2 == 1 or y2 == 1 or x2 == n or y2 == m)
        ans2 = 3;
    else
        ans2 = 4;
    cout << min({ans1, ans2, n, m}) << endl;
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