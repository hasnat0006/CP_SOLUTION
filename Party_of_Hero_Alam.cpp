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
int n;

set<vector<int>> s;

void HEROALAM(int i, vector<int> v) {
    if (i == n) {
        s.insert(v);
        return;
    }
    HEROALAM(i + 1, v);
    if (i > 0 and i < n - 1 and v[i - 1] == 0) {
        v[i] = 1;
        HEROALAM(i + 1, v);
    }
}

void solve() {
    cin >> n;
    vector<int> v(n, 0);
    HEROALAM(0, v);
    for(auto i : s) {
        for(auto j : i) 
            j == 0 ? cout << "H" : cout << "O";
        cout << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}