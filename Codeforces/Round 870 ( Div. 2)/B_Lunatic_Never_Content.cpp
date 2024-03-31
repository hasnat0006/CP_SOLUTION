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
int palindrome(vector<int> &v)
{
    for (int i = 0; i <= v.size() / 2; i++)
    {
        if ((v[i]) != (v[v.size() - i - 1]))
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int n, zero = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (palindrome(v))
    {
        cout << "0\n";
        return;
    }
    int low = 1, high = INT_MAX;
    // while (low <= high)
    // {
    //     int mid = (high + low) / 2;
    //     cout << mid << endl;
    //     if (palindrome(v, mid))
    //     {
    //         ans = mid;
    //         low = mid + 1;
    //     }
    //     else
    //         high = mid - 1;
    // }
    int m = -2;
    vector<int> temp;
    for (int i = 0; i <= v.size() / 2; i++)
        if ((v[i]) != (v[n - i - 1]))
            temp.pb((abs(v[i] - v[n - i - 1])));
    int ans = 0;
    for (auto it : temp)
        ans = __gcd(ans, it);
        cout<<ans<<endl;
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