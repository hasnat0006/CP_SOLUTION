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
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    map<int, int> m;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    for (int i = 0; i < n; i++)
    {
        // p[i] = {y[i], x[i]};
        if (m[x[i]] > y[i])
        {
            m.erase(x[i]);
            m[x[i]] = y[i];
        }
    }
    // sort(p.begin(), p.end());
    // sort(m.begin(), m.end());
    for (auto it : m)
        cout << it.first << " " << it.second << endl;
    int cost = 0, c = 1, ans = INT_MAX;
    // for (int i = 0; i < n; i++)
    // cout << p[i].first << " " << p[i].second << endl;
    cost = p[0].first;
    for (int i = 1; i < n; i++)
    {
        if (p[i].second > p[i - 1].second)
        {
            cost += p[i].first;
            c++;
        }
        if (c == 3)
        {
            ans = min(ans, cost);
            c = 0;
            cost = 0;
        }
    }
    if (c != 3)
        cost = -1;
    cout << cost << endl;
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