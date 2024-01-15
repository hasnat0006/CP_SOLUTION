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
    vector<int> increasing, decreasing;
    int temp = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] > temp) {
            increasing.push_back(v[i]);
            temp = v[i];
        }
        else if (v[i] < temp)
            break;
    }
    temp = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] > temp) {
            decreasing.push_back(v[i]);
            temp = v[i];
        }
        else if (v[i] < temp)
            break;
    }
    dbg(increasing, decreasing);
    cout << (increasing.size() + decreasing.size()) / 2 << endl;
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