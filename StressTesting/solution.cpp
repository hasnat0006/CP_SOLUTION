//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve()
{
    string a, b;
    cin >> a >> b;
    map<char, vector<int>> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]].push_back(i);
    }
    // dbg(mp);
    bool f = true;
    int id = -1;
    for (int i = 0; i < b.size(); i++)
    {
        char c = b[i];
        if (mp[c].size() == 0)
        {
            f = false;
            break;
        }
        int idx = lower_bound(vf(mp[c]), id) - mp[c].begin();
        // dbg(i, id, idx);
        if (mp[c][idx] > id)
            id = idx;
        else
        {
            f = false;
            break;
        }
    }
    f ? cout << "YES" << endl : cout << "NO" << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}