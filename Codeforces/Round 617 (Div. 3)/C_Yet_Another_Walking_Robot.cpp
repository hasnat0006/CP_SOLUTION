//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    map<pair<int, int>, int> mp;
    pair<int, int> ans;
    int dis = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mp[{x, y}] > 0 and i - mp[{x, y}] < dis)
        {
            dis = i - mp[{x, y}];
            ans = {mp[{x, y}], i};
        }
        mp[{x, y}] = i + 1;
        if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'U')
            y++;
        else if (s[i] == 'D')
            y--;
    }
    if (mp[{x, y}] > 0 and n - mp[{x, y}] < dis)
    {
        dis = n - mp[{x, y}];
        ans = {mp[{x, y}], n};
    }
    if (dis == INT_MAX)
        cout << "-1\n";
    else
        cout << ans.first << " " << ans.second << endl;
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