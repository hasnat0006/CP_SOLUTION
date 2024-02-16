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

// sum of first n natural numbers = n * (n + 1) / 2
// i have the sum. i need to find the value of n
// n * (n + 1) / 2 = sum
// n * (n + 1) = 2 * sum
// n^2 + n = 2 * sum
// n^2 + n - 2 * sum = 0
// n = (-1 + sqrt(1 + 8 * sum)) / 2
int findN(int sum) { return (-1 + sqrt(1 + 8 * sum)) / 2; }
int sumN(int n) { return n * (n + 1) / 2; }

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        int lagbe = n + ((i * (i + 1)) / 2);
        int x = findN(lagbe);
        if (sumN(x) == lagbe)
            ans.push_back({min(i, x), max(i, x)});
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
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