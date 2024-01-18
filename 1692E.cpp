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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), one;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            one.push_back(i);
    }
    if (one.size() < k) {
        cout << -1 << endl;
        return;
    }
    one.push_back(n);
    deque<int> q;
    int sum = 0, c = 0;
    int ans = inf;
    for (int i = 0; i < n; i++) {
        q.push_back(a[i]);
        sum += a[i];
        if (sum == k) {
            int id = lower_bound(one.begin(), one.end(), i + 1) - one.begin();
            ans = min(ans, c + n - one[id]);
            while (q.front() != 1) {
                q.pop_front();
                c++;
            }
            sum -= q.front();
            q.pop_front();
            c++;
        }
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