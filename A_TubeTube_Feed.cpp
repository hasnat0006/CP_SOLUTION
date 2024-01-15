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
    int n, sec;
    cin >> n >> sec;
    vector<int> time(n), value(n);
    vector<pair<int, int>> mix;
    for (int i = 0; i < n; i++)
        cin >> time[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    for (int i = 0; i < n; i++)
        mix.push_back({time[i], value[i]});
    vector<pair<int, int>> qualify;
    for (int i = 0; i < n; i++)
    {
        if (mix[i].first <= sec)
            qualify.push_back({mix[i].second, i + 1});
        sec--;
    }
    if (qualify.size() == 0)
    {
        cout << "-1\n";
        return;
    }
    sort(qualify.begin(), qualify.end());
    cout << qualify[qualify.size() - 1].second << endl;
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