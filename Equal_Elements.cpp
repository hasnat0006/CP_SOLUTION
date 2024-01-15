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
    vector<int> freq(200001);
    int c = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        mx = max(mx, freq[arr[i]]);
    }
    // sort(freq.rbegin(), freq.rend());
    // for (int i = 1; i < 200001; i++)
    // {
    //     c += freq[i];
    //     if (freq[i] == 0)
    //         break;
    // }
    cout << n - mx << endl;
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