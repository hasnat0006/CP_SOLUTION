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
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            cout << n << " ";
        }
        else {
            n *= 3;
            n++;
            cout << n << " ";
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}