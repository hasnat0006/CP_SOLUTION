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
    int sz = (n * (n - 1)) / 2;
    vector<int> v(sz);
    map<int, int> mp;
    for (int i = 0; i < sz; i++)
        cin >> v[i], mp[v[i]]++;
    sort(vf(v));
    dbg(v);
    int temp = 0;
    vector<int> ans(n);
    ans[0] = v[0];
    for (int i = 1; i < n; i++)
        temp += n - i, ans[i] = v[temp];
    if (mp.size() != n)
        ans[n - 1] = v[sz - 1];
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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