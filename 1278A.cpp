#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int f = 0, x, y, i;
    string p, h;
    getchar();
    cin >> p >> h;
    sort(p.begin(), p.end());
    int pl = p.length();
    int hl = h.length();
    x = h.length() - p.length();
    string temp;
    if (hl < pl)
        cout << "NO" << endl;
    else
    {
        for (i = 0; i <= x; i++)
        {
            temp = h.substr(i, pl);
            sort(temp.begin(), temp.end());
            if (temp == p)
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}