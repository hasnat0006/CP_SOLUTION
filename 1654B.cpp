#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string x, ans;
    cin >> x;
    //cout<<x;
    int f = 1, qj, c = 0;
    for (int i = 0; x[i]; i++)
    {
        for (qj = 1; x[qj]; qj++)
        {
            if (x[i] == x[qj])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
        {
            ans[c] = x[qj];
            c++;
        }
    }
    ans[c]='\0';
    cout<<ans<<endl;
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