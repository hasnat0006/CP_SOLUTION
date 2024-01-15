#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int bin_s(int arr[], int x, int n)
{
    int low = 0, high = n - 1;
    int mid = (high + low) / 2;
    while (low < high)
    {
        mid = (high + low) / 2; // 2 9 12 16 25
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
void solve()
{
    int n, x;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        arr[i] = x + arr[i - 1];
    }
    int k;
    cin >> k;
    int ans[k];
    for (int i = 0; i < k; i++)
        cin >> ans[i];
    int c = 0;
    while (k--)
    {
        int x = ans[c++];
        int pp = bin_s(arr, x, n);
        cout << pp + 1 << endl;
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