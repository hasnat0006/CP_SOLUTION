#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    // for (int i = 0; i < n; ++i)
    //     cout << v[i] << " ";
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        // cout << "x-> " << x << endl;
        // auto find = lower_bound(v.begin(), v.end(), x);
        // int temp = *find;
        int id = -1;
        bool f;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == x)
            {
                id = i + 1;
                f = true;
                break;
            }
            else if (v[i] > x)
            {
                id = i + 1;
                f = false;
                break;
            }
        }
        if (f)
            cout << "Yes " << id << endl;
        else
            cout << "No " << id << endl;
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