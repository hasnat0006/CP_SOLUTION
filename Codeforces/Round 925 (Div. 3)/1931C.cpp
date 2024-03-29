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
    int n, x;
    cin >> n;
    vector<int> v(n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
        cin >> x, v[i] = x, dq.push_back(x);
    dbg(v);
    int same = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (v[0] == v[i])
            same++;
        else
            break;
    }
    mx = max(mx, same);
    same = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v.back() == v[i])
            same++;
        else
            break;
    }
    mx = max(mx, same);
    dbg(mx);
    int ans = n - mx;
    int dlt = -1;
    while (dq.size() > 0) {
        if (dq.front() == v[0] && dq.back() == v.front()) {
            dlt = dq.front();
            dq.pop_back();
            if (dq.size())
                dq.pop_front();
        }
        else
            break;
    }
    while (dq.size() > 0) {
        if (dlt != -1) {
            if (dq.front() == dlt)
                dq.pop_front();
            else if (dq.back() == dlt)
                dq.pop_back();
            else
                break;
        }
        else
            break;
    }
    dbg(ans, dq.size());
    cout << min(ans, (int)dq.size()) << endl;
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