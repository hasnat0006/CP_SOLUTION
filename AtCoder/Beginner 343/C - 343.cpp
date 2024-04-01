//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 18:11:01            !//
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

int mod = 1000000007;
int inf = 1e18;

int qubic_Square_root(int n) {
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (m * m * m <= n)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

bool isPalindrome(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int num = 1;
    for(int i = 1; i * i * i <= n; i++){
        num = i * i * i;
        if(isPalindrome(num))
            ans.push_back(num);
    }
    dbg(ans);
    cout << ans.back() << endl;
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