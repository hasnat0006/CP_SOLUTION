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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &it : v)
        cin >> it;
    sort(vf(v));
    priority_queue<int> pq;
    pq.push((v.front() + n) - v.back() - 1);
    for (int i = 1; i < m; i++)
        pq.push(v[i] - v[i - 1] - 1);
    int ans = 0;
    int waste = 0;
    while (pq.size()) {
        if (pq.top() > waste) {
            int possible_ans = (pq.top() - waste - 1);
            ans += max(1LL, possible_ans);
            waste += 4;
            pq.pop();
        }
        else
            break;
    }
    dbg(ans);
    cout << n - ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}