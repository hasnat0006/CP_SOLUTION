#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, temp, k;
    cin >> n >> k;
    int arr[n + 1], copy[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        copy[i] = arr[i];
    }
    sort(copy, copy + n);
    copy[n] = 999999999999;
    map<int, int> first_time;
    for (int i = 0; i < n; i++)
        first_time[copy[i]] = copy[i + 1];
    arr[n] = 999999999999;
    int dorkar = 0;
    for (int i = 0; i < n; i++)
    {
        while (first_time[arr[i]] == arr[i + 1] and i < n)
            i++;
        dorkar++;
    }
    if (dorkar <= k)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}