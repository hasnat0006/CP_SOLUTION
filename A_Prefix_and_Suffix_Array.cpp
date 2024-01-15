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
    vector<string> v;
    for (int i = 0; i < (2 * n - 2); i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int c = 0;
    // for (auto it : v)
    //     cout << it << endl;
    for (int i = 0; i < (2 * n - 2) - 1; i++)
    {
        string temp = v[i];
        reverse(temp.begin(), temp.end());
        for (int j = i + 1; j < (2 * n - 2); j++)
        {
            if (v[j] == temp)
            {
                c += 2;
                break;
            }
        }
    }
    // cout << c << endl;
    if (c >= (2 * n - 2))
        cout << "YES\n";
    else
        cout << "NO\n";
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