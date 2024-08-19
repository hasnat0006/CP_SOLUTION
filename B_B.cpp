//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|08|2024 21:02:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

// smallest prime factor of a number.
int factors(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a <= sqrt(n); a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}
// complete factorization. call the remaining part in main function

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // here n is the number to be factorized
        while (x > 1) {
            int r = factors(x);
            if (r == 2)
                a[i]++;
            x /= r;
        }
    }
    cout << *min_element(vf(a)) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}