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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int c = 0, temp = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (v[j + 1] <= v[j])
                temp++;
            else
                break;
        }
        for (int k = i - 1; k >= 0; k--)
        {
            if (v[k] <= v[k + 1])
                temp++;
            else
                break;
        }
        c = temp + 1;
        ans = max(ans, c);
        // cout << c << " " << ans << endl;
    }
    cout << ans << endl;
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