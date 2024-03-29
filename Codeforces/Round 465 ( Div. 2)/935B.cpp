#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, right = 0, left = 0, it = 0;
    bool f = false;
    cin >> n;
    string str;
    cin >> str;
    // cout<<str;
    int x = 0, y = 0, cnt = 0;
    if (str[0] == 'U')
        y++;
    else
        x++;
    for (int i = 1; str[i]; i++)
    {
        if (x == y and str[i] == 'U' and str[i - 1] == 'U')
            cnt++;
        else if (x == y and str[i] == 'R' and str[i - 1] == 'R')
            cnt++;
        if (str[i] == 'U')
            y++;
        else if(str[i]=='R')
            x++;
    }
    cout << cnt << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}