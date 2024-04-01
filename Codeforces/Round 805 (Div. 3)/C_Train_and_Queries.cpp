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
    int n, q;
    cin >> n >> q;
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pair<int, int> v = m[x];
        if (v.first == 0)
        {
            v.first = (i + 1);
            v.second = (i + 1);
        }
        else
            v.second = (i + 1);
        m[x] = v;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> t1, t2;
        if (m[a].first == 0 or m[b].first == 0)
            cout << "NO\n";
        else
        {
            if (m[a].first < m[b].second)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}