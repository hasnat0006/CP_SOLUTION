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
    int n, x;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[n - 1] < i + 1 and f == 0)
            v.insert(v.begin(), v[n - 1]), v.pop_back(), f = 1;
        else if (f == 1)
            break;
    }
    int id = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == 1)
            id = i + 1;
    cout << n - id << endl;
}

int32_t main()
{
    // fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}