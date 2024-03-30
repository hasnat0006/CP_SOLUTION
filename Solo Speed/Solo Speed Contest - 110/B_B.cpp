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
float pi = acos(-1);
int inf = 1e18;

int binaryExponentiation(int base, int power) ////O(log2(power))
{
    if (power == 0)
        return 1;
    int ans = binaryExponentiation(base, power / 2);
    if (power % 2 == 1)
        return (((ans * ans) % mod) * base) % mod;
    return (ans * ans) % mod;
}

// 2^(n+1)-1
void solve()
{
    int n, x;
    cin >> n >> x;
    int ans = binaryExponentiation(2, n - 1) - 1;
    // cout << "ans: " << ans << endl;
    cout << ((ans + 1) * x) % mod << endl;
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