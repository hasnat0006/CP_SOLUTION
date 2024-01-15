#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
float height(float x, float y, float c)
{
    float low = 0, high = min(x, y), mid, h1, h2, a;
    while (high - low > 1e-6)
    {
        mid = (low + high) / 2;
        h1 = sqrt(x * x - mid * mid);
        h2 = sqrt(y * y - mid * mid);
        a = h1 * h2 / (h1 + h2);
        if (a > c)
            low = mid;
        else
            high = mid;
    }
    // cout << low << endl;
    return low;
}
void solve()
{
    float x, y, c;
    cin >> x >> y >> c;
    cout << fixed << setprecision(12) << height(x, y, c) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}