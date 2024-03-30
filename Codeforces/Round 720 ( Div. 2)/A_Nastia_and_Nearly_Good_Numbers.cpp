#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0, z = 0;
    bool f = true;
    int multi = 1;
    x = a * b;
    y = a;
    z = x + y;
    if (b == 1)
        cout << "NO\n";
    else
        cout << "YES\n"<< y << " " << x << " " << z << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}