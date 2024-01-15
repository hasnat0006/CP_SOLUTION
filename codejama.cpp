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
    int m, r, n;
    cin >> m >> r >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    bool f = true;
    if (v[0] - r > 0)
    {
        // cout << "3\n";
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int c = 0, cover = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // cout << "i->: " << i << endl;
        if ((v[i] + r) >= v[i + 1] - r)
        {
            cover = v[i] + r;
            if ((i + 2) < n)
            {
                if (v[i] + r >= v[i + 2] - r)
                {
                    i++;
                    // cover = v[i] + r;
                    // c++;
                    // continue;
                }
            }
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        c++;
    }
    // cout << c << endl;
    // cout << "Cover:-> " << cover << endl;
    if (v[v.size() - 1] + r >= m and cover < m)
        c++;
    if (v[v.size() - 1] + r < m)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}