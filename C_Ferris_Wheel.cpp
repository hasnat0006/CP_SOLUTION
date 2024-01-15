#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int c = 0, id = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = id; j < n; j++)
        {
            if (v[i] + v[j] < x)
            {
            }
            else if ((v[i] + v[j]) >= x)
            {
                c++;
                id = j;
                break;
            }
        }
    }
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