#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    string a, b;
    int z=0;
    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++)
        for (int j = 0; j+i-1 < a.length(); j++)
            if(b.find(a.substr(j,i))!=string::npos)
                z=max(i,z);
    int ans = (a.length() + b.length()) - (2 * z);
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}