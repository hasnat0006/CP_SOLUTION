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
int n, x, k, cnt;

int checkValidNode(int node, int k) {
    if (k < 0 || node > n)
        return 0;
    if (k == 0)
        return 1;
    int left = node, right = node;
    for (int i = 0; i < k; ++i) {
        left *= 2;
        if (left > n)
            return 0;
    }
    for (int i = 0; i < k; ++i) {
        right = right * 2 + 1;
        if (right > n)
            break;
    }
    return min(right, n) - min(left, n) + 1;
}

int completeBinaryTree(int node, int prev, int k) {
    if (node == 0 || node > n)
        return 0;
    if (k == 0)
        return 1;
    int left = node * 2;
    int right = node * 2 + 1;
    int ans = completeBinaryTree(node / 2, node, k - 1);
    if (left == prev)
        ans += checkValidNode(right, k - 1);
    else
        ans += checkValidNode(left, k - 1);
    return ans;
}

void solve() {
    cin >> n >> x >> k;
    cout << completeBinaryTree(x / 2, x, k - 1) + checkValidNode(x, k) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}