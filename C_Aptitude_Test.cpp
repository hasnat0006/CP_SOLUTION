#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int first_oc(int arr[], int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2; // 2 9 12 16 25
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid-1;
    }
    return low;
}
int last_oc(int arr[], int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low ) / 2;
        if (arr[mid] <= x)
            low = mid+1;
        else
            high = mid - 1;
    }
    return high;
}
void solve()
{
    int n, q, x, y;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
    {
        cin >> x >> y;
        int start = first_oc(arr, x, n);
        int end = last_oc(arr, y, n);
        // cout << start << " " << end << endl;
        cout << (end - start) + 1 << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}