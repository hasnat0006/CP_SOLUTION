//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|08|2024 21:00:18            !//
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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    int q;
    dbg(mp);
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        set<char> st;
        for (auto i : s) {
            st.insert(i);
        }
        if (s.size() != n or st.size() != mp.size()) {
            cout << "NO" << endl;
            continue;
        }
        int f = 0;
        for (auto i : mp) {
            int c = i.second.front();
            for (auto it : i.second) {
                if (s[it] != s[c]) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
        map<char, vector<int>> freq;
        for (int i = 0; i < n; i++) {
            freq[s[i]].push_back(i);
        }
        for (auto i : freq) {
            int c = i.second.front();
            for (auto it : i.second) {
                if (v[it] != v[c]) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
        if (f == 1) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
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