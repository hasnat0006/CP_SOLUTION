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
map<int, vector<int>> prime;
map<int, int> visited;

bool is_prime(int n)
{
    if (n <= 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void prime_generator(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))
        {
            if (is_prime(i))
                prime[n].pb(i);
            if (is_prime(n / i))
                prime[n].pb(n / i);
        }
    }
}

int bfs(int start, int m)
{
    visited.clear();
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < prime[k].size(); i++)
        {
            int x = k + prime[k][i];
            if (x <= m and !visited[x])
                q.push(x), visited[x] = visited[k] + 1;
            if (x == m)
                return visited[m];
        }
    }
    return visited[m];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) - 1 << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 2; i < 1005; i++)
        prime_generator(i);
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();
    return 0;
}