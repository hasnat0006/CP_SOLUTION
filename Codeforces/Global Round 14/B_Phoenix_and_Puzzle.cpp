#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n, pow = 1;
    bool f = false;
    cin >> n;
    // if (n % 18 == 0)
    // {
    //     cout << "YES\n";
    //     return;
    // }
    for (int i = 0; i <= n; i++) {
        if ((i * i * 2) > n) {
            f = false;
            break;
        }
        else if (i * i * 4 == n or i * i * 2 == n) {
            f = true;
            break;
        }
        // pow = pow * 2;
    }
    if (n == 1)
        cout << "NO\n";
    else if (f)
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