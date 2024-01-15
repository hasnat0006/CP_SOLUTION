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
int inf = INT_MAX;
const int N = 2 * 1e6 + 6;
vector<int> dp(N, -1);

int Number_of_coins(int k, vector<int> &coins)
{
   if (dp[k] != -1)
      return dp[k];
   if (k == 0)
      return 0;
   int ans = inf;
   for (auto i : coins)
   {
      if (k - i >= 0)
         ans = min(ans, Number_of_coins(k - i, coins) + 1);
      // dbg(ans);
   }
   return dp[k] = ans;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> coins(n);
   for (int i = 0; i < n; i++)
      cin >> coins[i];
   int ans = Number_of_coins(k, coins);
   if (ans == inf)
      cout << -1 << endl;
   else
      cout << ans << endl;
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