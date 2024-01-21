//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> car(n), charge(m);
    for (int i = 0; i < n; i++)
        cin >> car[i];
    for (int i = 0; i < m; i++)
        cin >> charge[i];
    sort(vr(car));
    sort(vr(charge));
    int ans = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        int total = charge[i] * h;
        ans += (min(total, car[i]));
    }
    cout << ans << endl;
    // debug(car);
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