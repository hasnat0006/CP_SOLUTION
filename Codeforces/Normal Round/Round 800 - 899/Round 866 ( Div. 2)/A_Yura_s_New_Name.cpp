//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    if (s[s.size() - 1] == '_')
    {
        cnt++;
        s.pb('^');
    }
    if (s == "^")
    {
        cnt++;
        s.pb('^');
    }
    if (s[0] == '_')
    {
        cnt++;
        s.insert(s.begin(), '^');
    }
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '_' and s[i - 1] == '_')
            cnt++;
    cout << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}