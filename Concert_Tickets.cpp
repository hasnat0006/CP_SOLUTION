//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#include "debug.h"
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), cus(m), mark(n);
    multimap<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp.insert({v[i], v[i]});
    }
    for (auto &i : cus)
        cin >> i;
    multimap<int, int>::iterator it = mp.begin();
    for (int i = 0; i < m; i++)
    {
        if (mp.size() == 0)
            cout << "-1\n";
        else if ((*it).first <= cus[i])
        {
            cout << (*it).first << endl;
            auto del = mp.find((*it).first);
            mp.erase((del));
            it = mp.begin();
        }
        else
            cout << "-1\n";
        // for (auto p : mp)
        //     cout << p.first << " " << p.second << endl;
    }
    sort(vf(v));
    debug(v);
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}