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
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v1[i] * 2 < v2[i]) or (v1[i] > v2[i] * 2))
        {
        }
        else
            c++;
    }
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