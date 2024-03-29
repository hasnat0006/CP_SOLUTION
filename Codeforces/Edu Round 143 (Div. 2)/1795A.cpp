#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    string s1, s2, final;
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());
    final = s1 + s2;
    // cout<<final<<endl;;
    int c = 1;
    for (int i = 0; i < final.length() - 1; i++) {
        if (final[i] == final[i + 1])
            c++;
    }
    if (c > 2)
        cout << "NO\n";
    else
        cout << "YES\n";
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