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
    vector<int> v(n);
    int highest = (n * (n + 1)) / 2;
    dbg(highest);
    bool f = true;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
        if (v[i] > highest)
            f = false;
    }
    unordered_map<int, int> mp;
    for (int i = 1; i < n - 1; i++)
    {
        int diff = v[i] - v[i - 1];
        cout<<diff<<" ";
        if (mp[diff] > 0 or diff < 2)
        {
            f = false;
            // break;
        }
        else
            mp[diff]++;
    }
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
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