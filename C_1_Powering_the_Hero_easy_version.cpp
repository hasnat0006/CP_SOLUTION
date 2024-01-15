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
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    vector<int> v;
    int zero = 0;
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // cout << "5\n";
        if (arr[i] == 0)
        {
            sort(v.rbegin(), v.rend());
            cout << "zero-> " << zero << endl;
            for (int k = 0; k < zero; k++)
                c += v[k];
            v.erase(v.begin(), v.end());
            zero++;
        }
        else
        {
            cout << arr[i] << endl;
            v.pb(arr[i]);
        }
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
    for (int k = 0; k < zero; k++)
        c += v[k];
    v.clear();
    cout << c << endl;
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