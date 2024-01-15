//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

int fact(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), final;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    for (int i = 0; i < n - 2; i++)
    {
        int koybar = nCr((n - i - 1), 2);
        while (koybar--)
            final.pb(v[i]);
    }
    // debug(final);
    while (q--)
    {
        int x;
        cin >> x;
        cout << final[x - 1] << endl;
    }
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}