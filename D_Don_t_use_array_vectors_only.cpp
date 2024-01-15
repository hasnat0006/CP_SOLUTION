#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    // sort(v.begin(), v.end());
    int x = 1;
    while (x != n)
    {
        if (x % 2 == 1)
        {
            sort(v.begin(), v.end());
            v.pop_back();
            x++;
        }
        else
        {
            sort(v.rbegin(), v.rend());
            v.pop_back();
            x++;
        }
    }
    cout << v[0] << endl;
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