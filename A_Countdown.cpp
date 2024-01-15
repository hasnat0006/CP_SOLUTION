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
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] > '0')
            c += 1 + (s[i] - '0');
    }
    if (s[n - 1] > '0')
        c += s[n - 1] - '0';
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