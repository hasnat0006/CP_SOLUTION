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
    return (fact(n) / (fact(r) * fact(n - r)));
}

void solve()
{
    int n, x;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> x, mp[x]++;
    int ans = 0;
    for (auto it : mp)
    {
        if (it.second >= 2)
            ans += nCr(it.second, 2);
    }
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    // cout << nCr(100000, 2) << endl;
    while (t--)
        solve();
    return 0;
}