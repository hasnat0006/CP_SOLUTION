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
    int n;
    cin >> n;
    vector<int> divisor, freq(n + 1);
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                divisor.pb(i), freq[i] = 1;
            else
                divisor.pb(i), divisor.pb(n / i), freq[i] = freq[n / i] = 1;
        }
    }
    sort(vf(divisor));
    int ans = 1;
    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = 2;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!freq[i])
            {
                ans = i;
                break;
            }
        }
    }
    // debug(ans);
    string s;
    char c = 'a';
    for (int i = 0; i < ans; i++)
        s.pb(c++);
    // debug(s);
    int x = 0;
    for (int i = ans; i < n; i++)
    {
        s.pb(s[(x++) % ans]);
    }
    cout << s << endl;
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