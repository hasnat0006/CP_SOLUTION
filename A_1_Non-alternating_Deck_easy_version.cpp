#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int card = n;
    int alice = 0, bob = 0;
    int ac = 0, bc = 0, i;
    for (i = 1; i <= n; i++)
    {
        if (alice + bob >= n)
            break;
        if (i == 1)
        {
            alice++;
            card--;
        }
        else if (bc < 2)
        {
            if (card < i)
                i = card;
            bob += i;
            card -= i;
            bc++;
            if (bc == 2)
                ac = 0;
        }
        else if (ac < 2)
        {
            if (card < i)
                i = card;
            alice += i;
            card -= i;
            ac++;
            if (ac == 2)
                bc = 0;
        }
        // cout << " i " << i << endl;
        // cout << alice << " " << bob << endl;
    }
    cout << alice << " " << bob << endl;
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