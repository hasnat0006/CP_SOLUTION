#include <bits/stdc++.h>
#define int long long
#define float double
long long mod = 1000000007;
using namespace std;
int fact(int n) {
    if (n == 0)
        return 1;
    return (((n % mod) * (fact(n - 1) % mod)) % mod);
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int durbaal = fact(n);
        int paisi_ans = (((n * (n - 1)) % mod) * (durbaal % mod)) % mod;
        cout << paisi_ans << endl;
    }
    return 0;
}
