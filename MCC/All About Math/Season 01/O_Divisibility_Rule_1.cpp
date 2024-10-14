//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|05|2024 00:18:39            !//
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

int factor(int n) {
    int a;
    if (n % 2 == 0)
        return 2;
    for (a = 3; a <= sqrtl(n); a += 2) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n, x, cnt = 0;
    cin >> n;

    auto digitSum = [](int k) {
        int sum = 0;
        while (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        return sum;
    };

    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt += digitSum(x);
    }
    cout << (cnt % 3 == 0 ? "Yes" : "No") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
