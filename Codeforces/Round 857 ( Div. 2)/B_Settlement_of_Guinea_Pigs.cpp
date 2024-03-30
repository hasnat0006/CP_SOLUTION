//!................  CG o nai CP o nai :)  ................!//
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int c1 = 0, c2 = 0, ans = 0;  //! c1 = known , c2 = unknown
    for (int i = 0; i < n; i++) {
        if (v[i] == 2) {
            c1 += c2;
            c2 = 0;
            if (c1 > 0)
                ans = max(ans, (c1 + 2) / 2);
        }
        else {
            c2++;
            if (c1 == 0)
                ans = max(ans, c2);
            else
                ans = max(ans, ((c1 + 2) / 2) + c2);
        }
    }
    cout << ans << endl;
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