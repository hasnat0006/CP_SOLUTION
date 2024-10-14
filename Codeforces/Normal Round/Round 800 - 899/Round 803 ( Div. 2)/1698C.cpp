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
    int n, m, k, x;
    cin >> n;
    vector<int> v(n), a;
    unordered_map<int, int> mp;
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        if (v[i] > 0)
            pos++, a.push_back(v[i]);
        else if (v[i] < 0)
            neg++, a.push_back(v[i]);
        else
            zero++;
    }
    if (pos > 2 or neg > 2) {
        cout << "NO" << endl;
        return;
    }
    if (pos == 0 and neg == 0) {
        cout << "YES" << endl;
        return;
    }
    zero = min(zero, 4LL);
    while (zero--)
        a.push_back(0);
    if (a.size() < 3) {
        cout << "NO" << endl;
        return;
    }
    n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j and j != k and i != k and !mp[a[i] + a[j] + a[k]]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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