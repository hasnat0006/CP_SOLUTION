//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
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
    int n, x;
    cin >> n;
    map<int, int> freq;
    map<int, int> mode;
    for (int i = 0; i < n; i++)
        cin >> x, freq[x]++;
    for (auto it : freq)
        mode[it.second]++;
    int ans, temp = -1 * inf;
    for (auto it : mode)
    {
        if (temp < it.second)
            ans = it.first, temp = it.second;
        // dbg(temp);
    }
    // ans = min(ans, *it.second.begin());
    cout << ans << endl;
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