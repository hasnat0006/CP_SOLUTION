//!................  CG o nai CP o nai :)  ................!//
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int l, w;
bool valid(int x, int y) { return x > 0 and x <= l and y > 0 and y <= w; }
void solve()
{
    int x, y;
    cin >> l >> w >> x >> y;
    int q, c = 0;
    cin >> q;
    int que = q;
    int ans = 0, steps;
    while (que--)
    {
        int t1, t2;
        steps = 0;
        cin >> t1 >> t2;
        int low = 1, high = INT_MAX, mid;
        while (low <= high)
        {
            mid = (high + low) / 2;
            int next_x = x + (mid * t1);
            int next_y = y + (mid * t2);
            if (valid(next_x, next_y))
            {
                steps = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        ans += steps;
        x += (t1 * steps);
        y += (t2 * steps);
    }
    cout << ans << endl;
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