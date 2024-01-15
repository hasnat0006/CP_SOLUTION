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
      return 1;
   int ways = 0;
   for (auto i : coins)
   {
      if (k - i >= 0)
         ways += Number_of_coins(k - i, coins);
      // dbg(ways);
   }
   return dp[k] = ways;
}

int temp(int id, int k, vector<int> &coins)
{
   if(id==0)
      return 
   if (dp[k] != -1)
      return dp[k];
   if (k == 0)
      return 1;
   int ways = 0;
   for (auto i = 0; i < k; i += coins[id])
   {
      if (k - i >= 0)
         ways += temp(id - 1, k - i, coins);
      // dbg(ways);
   }
   return dp[k] = ways;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> coins(n);
   for (int i = 0; i < n; i++)
      cin >> coins[i];
   int ways = Number_of_coins(k, coins);
   cout <<
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