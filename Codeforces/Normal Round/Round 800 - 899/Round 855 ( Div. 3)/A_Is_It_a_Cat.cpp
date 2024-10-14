#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n;
    bool f = true;
    cin >> n;
    string s, ans;
    cin >> s;
    int m = 0, e = 0, o = 0, w = 0, c = 0, extra = 0;
    for (int i = 0; i < n; i++)
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = s[i] + 32;
    ans.pb(s[0]);
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            ans.pb(s[i]);
    // cout << ans << endl;
    if (ans == "meow")
        cout << "YES\n";
    else
        cout << "NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}