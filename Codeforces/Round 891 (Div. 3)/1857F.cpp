//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve()
{
    int n, temp;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> temp, mp[temp]++;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int c = 0;
        int ai = (x + sqrt((x * x) - 4 * y)) / 2;
        int aj = x - ai;
        dbg(ai, aj);
        if (ai + aj == x and ai * aj == y)
        {
            if (mp[ai] and mp[aj] and ai == aj)
                c += (((mp[ai] - 1) * (mp[ai])) / 2);
            else if (mp[ai] and mp[aj] and ai + aj == x)
                c += (mp[aj] * mp[ai]);
        }
        cout << c << " ";
    }
    cout << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}