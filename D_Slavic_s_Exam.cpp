//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|08|2024 21:16:28            !//
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


void solve() {
    string t, s;
    cin >> t >> s;
    int n = t.size(), m = s.size();
    int j = 0;
    for (int i = 0; i < n; i++){
        if(t[i] == s[j])
            j++;
        else if(t[i] == '?')
            t[i] = s[j++];
        if(j == m)
            break;
    }
    if(j != m){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
        t[i] == '?' ? cout << s[0] : cout << t[i];
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}