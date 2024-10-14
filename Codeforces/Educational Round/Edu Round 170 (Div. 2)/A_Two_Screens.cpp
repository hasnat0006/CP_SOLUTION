//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 20:36:55            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    string A, B;
    if (n < m)
        A = s1, B = s2;
    else
        A = s2, B = s1;
    n = A.size(), m = B.size();
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == B[id])
            id++;
        else
            break;
    }
    if (id != 0) {
        cout << n + m + 1 - id << endl;
    }
    else
        cout << n + m << endl;
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