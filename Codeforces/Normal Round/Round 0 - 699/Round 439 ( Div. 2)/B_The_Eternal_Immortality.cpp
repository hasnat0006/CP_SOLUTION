#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
int fact(int x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (b - a >= 10)
        cout << "0" << endl;
    else
    {
        int temp = 1;
        for (int i = a + 1; i <= b; i++)
            temp = (temp * (i % 10)) % 10;
        cout << temp << endl;
    }
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}