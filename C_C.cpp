//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define dbg(x...)
// #define dbgc(x...)
// #endif
using namespace std;
using namespace std;
using namespace __gnu_pbds;

// #define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)
// #define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1000000007;
int inf = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {abs(x - y), {x, y}};
    }
    sort(vf(v));
    // dbg(v);
    int ans = 0;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> taken;
    // o_set<int> taken;
    //  taken.insert(10);
    for (int i = 0; i < n; i++)
    {
        auto temp = v[i];
        int l = temp.second.first, r = temp.second.second;
        if (taken.find(l) == taken.end())
            taken.insert(l), ans++;
        else if (taken.find(r) == taken.end())
            taken.insert(r), ans++;
        else
        {
            int suru = taken.order_of_key(l) + 1;
            int sesh = taken.order_of_key(r) + 1;
            int maje_ase = sesh - suru - 1;
            if (maje_ase > 0)
            {
                ans++;
                while (suru <= sesh)
                {
                    int val = *taken.find_by_order(suru);
                    int val2 = *taken.find_by_order(sesh);
                    if (taken.find(val) == taken.end())
                    {
                        taken.insert(val);
                        break;
                    }
                    else if (taken.find(val2) == taken.end())
                    {
                        taken.insert(val);
                        break;
                    }
                    suru++;
                    sesh--;
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
/*
1
7
1 2
3 4
4 5
5 5
6 6
12 12
6 12
*/
