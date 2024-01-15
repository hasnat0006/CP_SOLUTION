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
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    int val = 0;
    for (auto it : st)
        val += it.second - it.first + 1;
    dbg(val);
    if (val % k == 0)
        cout << 0 << endl;
    else. Tamal moos Aminook Ami n . noob noob bot Pyzohello GF = 1+24 AP/P € , Ro =
        cout << k - (val % k) << endl;
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