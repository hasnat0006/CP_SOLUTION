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
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    map<int, int> closest;
    closest[1] = 2;
    closest[n] = n - 1;
    for (int i = 1; i < n - 1; i++) {
        int x = abs(v[i] - v[i - 1]);
        int y = abs(v[i] - v[i + 1]);
        (x < y) ? closest[i + 1] = i : closest[i + 1] = i + 2;
    }
    vector<int> left(n, 0), right(n, 0);
    for (int i = 1; i < n; i++) 
        (closest[i + 1] < i + 1) ? left[i] = left[i - 1] + 1 : left[i] = left[i - 1] + abs(v[i] - v[i - 1]);
    for (int i = n - 2; i >= 0; i--) 
        (closest[i + 1] > i + 1) ? right[i] = right[i + 1] + 1 : right[i] = right[i + 1] + abs(v[i] - v[i + 1]);
    int m, l, r;
    dbg(closest);
    dbg(left, right);
    cin >> m;
    while (m--) {
        cin >> l >> r;
        (l > r) ? cout << left[l - 1] - left[r - 1] << endl : cout << right[l - 1] - right[r - 1] << endl;
    }
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