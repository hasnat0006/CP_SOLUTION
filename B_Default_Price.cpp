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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> price(m);
    map<string, int> mp;
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        mp[x] = i + 1;
    }
    cin >> price[0];
    for (int i = 1; i <= m; i++)
        cin >> price[i];
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]])
            cost += price[mp[v[i]]];
        else
            cost += price[0];
    }
    cout << cost << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i),
        solve();
    return 0;
}