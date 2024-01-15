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
    vector<int> v(n), ans, temp;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    int mx = v[0] == n ? n - 1 : n;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == mx)
        {
            for (int j = i; j < n; j++)
                ans.pb(v[j]);
            for (int j = 0; j < i - 1; j++)
                temp.pb(v[j]);
            if (i == n - 1)
                temp.pb(v[i - 1]);
            else
                ans.pb(v[i - 1]);
            break;
        }
    }
    while (!temp.empty())
    {
        if (temp.front() > temp.back())
        {
            for (auto it : temp)
                ans.pb(it);
            break;
        }
        else
        {
            ans.pb(temp.back());
            temp.pop_back();
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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