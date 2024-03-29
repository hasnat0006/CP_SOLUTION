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

int mx;

void build(int ti, int low, int high, vector<int> &v, vector<int> &seg)
{
    if (high == low)
    {
        seg[ti] = v[low];
        mx = max(mx, seg[ti]);
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ti + 1, low, mid, v, seg);
    build(2 * ti + 2, mid + 1, high, v, seg);
    seg[ti] = min(seg[2 * ti + 1], seg[ti * 2 + 2]);
    mx = max(mx, seg[ti] * (high - low + 1));
    dbg(mx, seg[ti]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), seg(4 * n);
    for (int &i : v)
        cin >> i;
    build(0, 0, n - 1, v, seg);
    cout << mx << "\n";
    mx = 0;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}