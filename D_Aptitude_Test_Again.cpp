#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int first_oc(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int last_oc(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v1(n), v2(n);
    vector<int> que(q);
    for (int i = 0; i < n; i++)
        cin >> v1[i] >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while (q--)
    {
        int temp, c = 0;
        cin >> temp;
        int start = first_oc(v2, temp, n);
        int end = last_oc(v1, temp, n);
        c = end - start + 1;
        cout << c << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        cout << "Case " << l + 1 << ":\n";
        solve();
    }
    return 0;
}