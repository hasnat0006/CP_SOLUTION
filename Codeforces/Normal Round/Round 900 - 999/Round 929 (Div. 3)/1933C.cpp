//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 21:03:44            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int binaryExp(int base, int power) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    // cout << a << " " << b << " " << l << endl;
    int maxA = 0;
    while (binaryExp(a, maxA) <= l)
        maxA++;
    int maxB = 0;
    while (binaryExp(b, maxB) <= l)
        maxB++;
    set<int> divisors;
    for (int i = 0; i <= maxA; i++) {
        for (int j = 0; j <= maxB; j++) {
            int temp = binaryExp(a, i) * binaryExp(b, j);
            if (l % temp == 0)
                divisors.insert(l / temp);
        }
    }
    cout << divisors.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}