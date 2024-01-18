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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int id = 0, mx = -1, f = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            id = i;
            f = 1;
            break;
        }
        else if (s[i] - 'a' > mx) {
            mx = s[i] - 'a';
            id = i;
        }
    }
    if (s.back() - 'a' > mx and !f) {
        mx = s.back() - 'a';
        id = n - 1;
    }
    dbg(id);
    if (s[0] > s[id]) {
        id = 0;
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (i == id)
            continue;
        ans += s[i];
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // dbg(i, "-----------");
        solve();
    }
    return 0;
}