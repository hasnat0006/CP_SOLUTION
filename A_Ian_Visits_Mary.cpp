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
    int a, b;
    cin >> a >> b;
    int n;
    vector<pair<int, int>> v;
    if (a == 1 and b == 1)
    {
        n = 1;
        v.pb({a, b});
    }
    else if (a % b == 0 or b % a == 0)
    {
        n = 2;
        v.pb({1, b / 2});
        if(v[v.size() - 1].first==v[v.size() - 1].second){
            v.pop_back();
            v.pb({1,0});
        }
        v.pb({a, b});
    }
    else
    {
        n = 1;
        v.pb({a, b});
    }
    cout << n << endl;
    for (auto it : v)
        cout << it.first << " " << it.second << endl;
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