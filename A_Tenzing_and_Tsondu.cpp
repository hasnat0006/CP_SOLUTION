//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        y += b[i];
    }
    if (x > y)
        cout << "Tsondu\n";
    else if (y > x)
        cout << "Tenzing\n";
    else
        cout << "Draw\n";
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