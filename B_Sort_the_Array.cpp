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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> final = v;
    sort(vf(final));
    if (v == final) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    int c = 1, id = 0;
    int idx = -1;
    while (c) {
        if (v[id] != final[id]) {
            int value = final[id];
            for (int i = id; i < n; i++) {
                if (v[i] == value) {
                    idx = i;
                    break;
                }
            }
        }
        idx != -1 ? c = 0 : id++;
    }
    if (idx != -1) {
        reverse(v.begin() + id, v.begin() + idx + 1);
    }
    if (v == final) {
        cout << "yes" << endl;
        cout << id + 1 << " " << idx + 1 << endl;
    }
    else
        cout << "no" << endl;
    dbg(id, idx, v);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}