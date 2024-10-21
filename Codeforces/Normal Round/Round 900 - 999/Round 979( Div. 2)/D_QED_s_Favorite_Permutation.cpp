//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|10|2024 21:08:26            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

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

    auto swapAble = [&](int i){
        if(s[i] == 'R' or s[i + 1] == 'L') return true;
        return false;
    };
    int cnt = 0;
    
    while (q--) {
        int x;
        cin >> x;
        if (s[x] == 'L')
            s[x] = 'R';
        else
            s[x] = 'L';
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