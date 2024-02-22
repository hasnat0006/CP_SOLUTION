//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
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
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

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
    int n;
    cin >> n;
    if(n < 5)
    {
        cout << n * 0 << endl;
        return;
    }
    string s = bitset<35>(n).to_string();
    reverse(vf(s));
    int bit = log2(n);
    if(n == binaryExp(2, bit))
    {
        cout << 0 << endl;
        return;
    }
    vector<int> ans;
    for (int i = 0; i < min(35ll, bit); i++) {
        if (s[i] == '1') {
            ans.push_back(i);
            break;
        }
    }
    for (int i = ans.back(); i < min(35ll, bit); i++) {
        if (s[i] == '0') {
            ans.push_back(i);
        }
    }
    ans.pop_back();
    dbg(ans);
    int res = 0;
    for (int i = 0; i < ans.size(); i++) {
        res += binaryExp(2, ans[i]);
    }
    cout << res << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}