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

vector<int> v;
int n, m;

void findSum(int i, int j, vector<int> &a, int sum = 0) {
    if (i > j) {
        a.push_back(sum);
        return;
    }
    findSum(i + 1, j, a, sum);
    sum += v[i], sum %= m;
    findSum(i + 1, j, a, sum);
}

void solve() {
    cin >> n >> m;
    v.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i], v[i] %= m;
    vector<int> a, b;
    findSum(0, n / 2 - 1, a);
    findSum(n / 2, n - 1, b);
    dbg(a, b);
    int ans = 0;
    sort(vf(b));
    for (int i = 0; i < a.size(); i++) {
        int low = 0, high = b.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (b[mid] + a[i] < m) {
                low = mid;
            }
            else
                high = mid - 1;
        }
        ans = max(ans, a[i] + b[low]);
        ans = max(ans, a[i] + b.back() - m);
    }
    cout << ans << endl;
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