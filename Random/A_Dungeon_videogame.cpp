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
int c = 0;
void solve()
{
    // cout << c++ << "--> " << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int start = 0, end, sum = 0;
    map<int, pair<int, int>> mp;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            if (!f)
            {
                start = i;
                f = true;
            }
            sum += v[i];
        }
        else if (sum)
        {
            end = i;
            mp[sum] = {start, end};
            f = false;
            // cout << start << " " << end << " " << sum << endl;
            sum = 0;
        }
    }
    if (v[n - 1] < 0)
    {
        end = n;
        mp[sum] = {start, end};
        // cout << start << " " << end << " " << sum << endl;
    }
    sum = 0;
    if (mp.size())
    {
        int x, y;
        for (auto it : mp)
        {
            x = it.second.first, y = it.second.second;
            break;
        }
        // cout << "xy " << x << " " << y << endl;
        v.erase(v.begin() + x, v.begin() + y);
        sum -= (y - x);
    }
    for (auto it : v)
        sum += it;
    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;
    cout << sum << endl;
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