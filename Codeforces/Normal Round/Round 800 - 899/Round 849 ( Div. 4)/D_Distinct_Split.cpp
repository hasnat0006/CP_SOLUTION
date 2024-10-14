#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int cntDistinct(string str)
{
    set<char> s;
    for (int i = 0; i < str.size(); i++)
        s.insert(str[i]);
    return s.size();
}
void solve()
{
    int n, ans = INT_MIN;
    cin >> n;
    string s;
    cin >> s;
    int l = s.length();
    set<char> x;
    int pre[l], suf[l];
    for (int i = 0; i < s.length(); i++)
    {
        x.insert(s[i]);
        pre[i] = x.size();
    }
    x.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        x.insert(s[i]);
        suf[i] = x.size();
    }
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, (suf[i+1] + pre[i]));
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