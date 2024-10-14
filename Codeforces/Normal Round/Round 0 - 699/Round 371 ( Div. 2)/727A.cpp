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

int a, b;
void find_ans(int x, vector<int> v) {
    dbg(v);
    if (x > b)
        return;
    if (x == b) {
        cout << "YES" << endl;
        cout << v.size() << endl;
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        exit(0);
        return;
    }
    v.push_back(x * 2);
    find_ans(x * 2, v);
    v.pop_back();
    v.push_back(x * 10 + 1);
    find_ans(x * 10 + 1, v);
}

void solve() {
    cin >> a >> b;
    find_ans(a, {a});
    cout << "NO" << endl;
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