#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int power(int a, int b, int n) {
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        if (ans >= n)
            return ans;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1)
        cout << "-1\n";
    else
        cout << "1 " << n / 2 << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}