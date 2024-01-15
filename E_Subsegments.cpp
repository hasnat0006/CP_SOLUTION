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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<int, int> num, occur;
    for (int j = 0; j < k; j++)
    {
        num[v[j]]++;
        if (num[v[j]] == 1)
            occur[v[j]] = 1;
        else
            occur.erase(v[j]);
    }
    if (occur.empty())
        cout << "Nothing" << endl;
    else
    {
        auto it = occur.rbegin();
        cout << it->first << endl;
    }
    for (int i = k; i < n; i++)
    {
        num[v[i - k]]--;
        num[v[i]]++;
        if (num[v[i - k]] == 1)
            occur[v[i - k]] = 1;
        else
            occur.erase(v[i - k]);
        if (num[v[i]] == 1)
            occur[v[i]] = 1;
        else
            occur.erase(v[i]);
        if (occur.empty())
            cout << "Nothing" << endl;
        else
        {
            auto it = occur.rbegin();
            cout << it->first << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}