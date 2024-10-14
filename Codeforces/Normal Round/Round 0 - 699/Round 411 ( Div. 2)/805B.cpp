#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, i;
    cin >> n;
    string s;
    int f = 0;
    for (i = 0; i < n; i++)
    {
        if (f == 0)
        {
            s.push_back('a');
            f = 1;
        }
        else if (f == 1)
        {
            s.push_back('a');
            f = 2;
        }
        else if (f == 2)
        {
            s.push_back('b');
            f = 3;
        }
        else
        {
            s.push_back('b');
            f = 0;
        }
    }
    cout<<s<<endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}