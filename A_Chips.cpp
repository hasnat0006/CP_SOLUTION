#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, m;
    bool f = false;
    cin >> n >> m;
    int chip = 0, ans = -1, i;
    for (i = n; i >= 1; i--)
    {
        int jog=(i*(i+1))/2;
        if(jog>m)
        {

        }
        else if(jog<m)
        {
            ans=m-jog;
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}