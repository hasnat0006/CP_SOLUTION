#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, h;
    cin >> n >> h;
    for (int i = 1; i < n; i++)
    {
        float temp = (i*1.0)/(n*1.0);
        float ans = (h*1.0) * (sqrt(temp));
        // cout << ans << " ";
        printf("%.12lf ",ans);
    }
    cout<<endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}