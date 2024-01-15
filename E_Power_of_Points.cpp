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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> temp = v;
    sort(vf(v));
    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++)
        prefix_sum[i] = (prefix_sum[i - 1] + v[i]);
    dbg(prefix_sum);
    map<int, int> ans;
    for (int i = 0; i < n; i++)
    {
        if(ans[v[i]])
            continue;
        if (i != n - 1) // going to right side.
        {
            int from_prefix = prefix_sum.back() - prefix_sum[i] + v[i];
            int gun_hobe = n - i;
            int temp_ans = from_prefix - (gun_hobe * v[i]);
            dbg(from_prefix, gun_hobe * v[i], gun_hobe * 1);
            ans[v[i]] += temp_ans;
            dbg(v[i], temp_ans)
        }
        if (i != 0) // now going to left side.
        {
            int temp_ans = (v[i] * i) - prefix_sum[i - 1];
            dbg((v[i] * i), prefix_sum[i - 1], (i * 1));
            ans[v[i]] += temp_ans;
            dbg(v[i], temp_ans)
        }
        ans[v[i]] += n;
    }
    // dbg(ans);
    for (int i = 0; i < n; i++)
        cout << ans[temp[i]] << " ";
    cout << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i),
        solve();
    return 0;
}