//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2024 09:14:50            !//
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

int GLMSB(int n) {
    // GLMSB = Get Left Most Set Bit
    int pos = 0;
    while (n > 0) {
        pos++;
        n >>= 1;
    }
    return pos;
}

int TotalSetBitsFrom1ToN(int n) {
    int id = GLMSB(n);
    int totalRep, mod, nearestPow;
    int totalSetBit = 0, addRem = 0, curr = 0;
    for (int i = 1; i <= id; ++i) {
        nearestPow = 1LL << i;
        if (nearestPow > n) {
            int lastPow = 1LL << (i - 1);
            mod = n % lastPow;
            totalSetBit += mod + 1;
        }
        else {
            if (i == 1 && n % 2 == 1) {
                totalRep = (n + 1) / nearestPow;
                mod = nearestPow % 2;
                addRem = 0;
            }
            else {
                totalRep = n / nearestPow;
                mod = n % nearestPow;
                if (mod >= (nearestPow / 2))
                    addRem = mod - (nearestPow / 2) + 1;
                else
                    addRem = 0;
            }
            curr = totalRep * (nearestPow / 2) + addRem;
            totalSetBit += curr;
        }
    }
    return totalSetBit;
}
int oneCnt(int start, int end) {
    int cnt = 0;
    for (int i = start; i <= end; i++) {
        cnt += __builtin_popcount(i);
    }
    return cnt;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << TotalSetBitsFrom1ToN(b) - TotalSetBitsFrom1ToN(a - 1) << endl;
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