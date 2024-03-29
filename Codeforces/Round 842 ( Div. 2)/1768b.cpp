#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // a[i] = arr[i];
    }
    // sort(a, a + n);
    int c = 0, x = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            x++;
        else
            c++;
    }
    int ans;
    if (c % k == 0)
        ans = c / k;
    else
        ans = (c / k) + 1;
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}