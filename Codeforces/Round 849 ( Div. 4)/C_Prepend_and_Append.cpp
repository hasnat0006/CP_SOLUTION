#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    while ((s[0] == '0' and s[s.length() - 1] == '1') or (s[0] == '1' and s[s.length() - 1] == '0'))
    {
        s.pop_back();
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());
    }
    int ans = s.length();
    cout << ans << endl;
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