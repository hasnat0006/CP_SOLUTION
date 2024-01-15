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
    int n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int low = 1;
    int high = h;
    int ans = h;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int damage = 0;
        for (int i = 1; i < n; i++)
        {
            int x = v[i] - v[i - 1];
            if (x < mid)
                damage += x;
            else
                damage += mid;
            if (i == n - 1)
                damage += mid;
        }
        if (damage >= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        // cout << "high: " << high << " Low: " << low << endl;
        // cout << "damage-> " << damage << endl;
        // cout << ans << endl;
    }
    cout << ans << endl;
    // cout << endl;
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