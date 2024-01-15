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
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= n)
            mp[x]++;
    }
    // dbg(st);
    unordered_map<int, int> ans;
    int c = 0;
    for (auto it : mp)
    {
        int temp = it.first;
        while (temp <= n)
        {
            ans[temp] += (it.second);
            c = max(c, ans[temp]);
            temp += it.first;
        }
        dbg(ans);
        // if (it.second > 1)
    }
    dbg(ans);
    cout << c << endl;
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