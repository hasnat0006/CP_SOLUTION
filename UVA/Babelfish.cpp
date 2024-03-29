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
    int n = 100000;
    map<string, string> m;
    while (n--)
    {
        string a, b, x;
        getline(cin, x);
        if (x == "")
            break;
        else
        {
            int i = x.find(" ");
            for (int j = 0; j < i; j++)
                a.pb(x[j]);
            for (int j = i + 1; j < x.length(); j++)
                b.pb(x[j]);
            // cout << a << endl;
            // cout << b << endl;
            m[b] = a;
        }
    }
    // for (auto it : m)
        // cout << it.first << " " << it.second << endl;
    string x;
    while (cin >> x)
    {
        if (m[x] == "")
            cout << "eh\n";
        else
            cout << m[x] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}