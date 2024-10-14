
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = x ^ arr[i];
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^(x ^ arr[i]);
    }
    // cout<<x<<endl;
    // cout<<ans<<endl;
    if (ans == 0)
        cout << x << endl;
    else
        cout << "-1\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}