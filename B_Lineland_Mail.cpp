#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x, y;
    vector<pair<int, int>> v(n);
    x = abs(arr[0] - arr[n - 1]);
    y = abs(arr[0] - arr[1]);
    v[0] = {y, x};
    for (int i = 1; i < n - 1; i++)
    {
        x = max((abs(arr[i] - arr[0])), abs(arr[i] - arr[n - 1]));
        y = min((abs(arr[i] - arr[i - 1])), (abs(arr[i] - arr[i + 1])));
        v[i] = {y, x};
    }
    x = abs(arr[n - 1] - arr[0]);
    y = abs(arr[n - 1] - arr[n - 2]);
    v[n - 1] = {y, x};
    for (auto it : v)
        cout << it.first << " " << it.second << endl;
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