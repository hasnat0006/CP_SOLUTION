//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|10|2024 22:27:12            !//
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

set<string> st;

void isConsicutive(string s) {
    dbg(s);
    for (int len = 1; len <= 12 / 2; len++) {
        int f = 1;
        int k = 0;
        for (int KK = k + len; KK < 12; KK++) {
            if (s[k] != s[KK]) {
                f = 0;
                break;
            }
            k++;
            k %= len;
        }
        if(f){
            st.insert(s);
        }
    }
}

void solve() {
    int n = 12;
    int num = 1 << n;
    // isConsicutive("10111011");
    for (int i = 0; i < num; i++) {
        // cout << bitset<12>(i) << endl;
        string s = bitset<12>(i).to_string();
        isConsicutive(s);
    }
    cout << st.size() << endl;
    for(auto x: st){
        cout << x << endl;
    }
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