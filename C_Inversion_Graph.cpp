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
    vector<int> v(n);
    map<int, int> eaten, rem;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        rem[v[i]] = 1;
    }
    int mx = n, c = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        eaten[v[i]] = 1;
        rem.erase(v[i]);
        if (!rem.empty() and mx == v[i])
        {
            auto it = eaten.begin();
            int small = it->first;
            auto it2 = rem.rbegin();
            int large = it2->first;
            mx = large;
            if (large < small)
                c++;
        }
    }
    cout << c << endl;
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