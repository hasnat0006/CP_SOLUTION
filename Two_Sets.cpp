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
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 0)
    {
        vector<int> v1, v2;
        int c = 0, lagbe = sum / 2;
        for (int i = n; i > 0; i--)
        {
            c += i;
            if (c <= lagbe)
                v1.pb(i);
            else
            {
                v2.pb(i);
                c -= i;
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        cout << "YES\n";
        cout << v1.size() << endl;
        for (auto it : v1)
            cout << it << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (auto it : v2)
            cout << it << " ";
        cout << endl;
    }
    else
        cout << "NO\n";
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