//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|04|2024 18:52:43            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int binaryExp(int base, int power, int MOD = mod) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

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

void solve() {
    int l, r;
    cin >> l >> r;
    set<pair<int, int>> ans;
    if (l == 0) {
        int x = 0, n = r;
        while (n > 1) {
            x++;
            n /= 2;
        }
        ans.insert({0, binaryExp(2, x)});
        l = binaryExp(2, x);
    }
    while (l < r) {
        int n = l, two = 0;
        while (n > 1) {
            int fact = factors(n);
            if (fact == 2)
                two++;
            n /= fact;
        }
        dbg(two, l, r);
        // 2 ^ two * x ...2 ^ (two - 1) * (x + 1)
        set<pair<int, int>> temp;
        for (int i = two; i >= 0; i--) {
            int iii = binaryExp(2, i);
            int jjj = l / iii;
            if (iii * (jjj + 1) <= r) {
                // ans.insert({iii * jjj, iii * (jjj + 1)});
                int tempL = iii * jjj, tempR = iii * (jjj + 1);
                ans.insert({tempL, tempR});
                l = tempR;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}