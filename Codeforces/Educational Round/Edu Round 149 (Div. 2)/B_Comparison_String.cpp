//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            c2 = 0;
            c1++;
            c = max(c, c1);
        }
        else
        {
            c1 = 0;
            c2++;
            c = max(c, c2);
        }
    }
    cout << c + 1 << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}