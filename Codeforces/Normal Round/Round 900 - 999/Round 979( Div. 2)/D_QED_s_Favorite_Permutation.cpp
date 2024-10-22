//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|10|2024 21:08:26            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    string s;
    cin >> s;
    s.insert(s.begin(), 'X');

    auto swapAble = [&](int i) {
        if (s[i] == 'L' and s[i + 1] == 'R')
            return false;
        return true;
    };
    int cnt = 0;
    vector<int> prefixMax(n + 1);
    for (int i = 1; i <= n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], v[i]);
        if (prefixMax[i] > i) {
            if (!swapAble(i)) {
                cnt++;
                dbg(i, cnt);
            }
        }
    }
    dbg(cnt);

    while (q--) {
        int x;
        cin >> x;
        int ageSomoshaAse = 0, poreSomoshaAse = 0;
        if(prefixMax[x - 1] > x - 1 and !swapAble(x - 1)) 
            ageSomoshaAse++;
        if(prefixMax[x] > x and !swapAble(x)) 
            poreSomoshaAse++;
        s[x] = (s[x] == 'R' ? 'L' : 'R');
        // somosha dhur kora jai kina check korbo
        if(ageSomoshaAse and swapAble(x - 1)) 
            cnt--;
        if(poreSomoshaAse and swapAble(x)) 
            cnt--;
        // new somosha add hoise kina check korbo
        if(prefixMax[x - 1] > x - 1 and !swapAble(x - 1)) 
            cnt++;
        if(prefixMax[x] > x and !swapAble(x))
            cnt++;
        cout << (cnt == 0 ? "YES" : "NO") << endl;
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