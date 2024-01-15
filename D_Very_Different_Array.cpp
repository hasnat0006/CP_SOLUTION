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

void print(deque<int> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    deque<int> a, b;
    vector<int> v(n), vv(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> vv[i];
    // sort(vf(v));
    // sort(vf(vv));
    for (int i = 0; i < n; i++)
        a.push_back(v[i]);
    for (int i = 0; i < m; i++)
        b.push_back(vv[i]);
    sort(vf(a));
    sort(vf(b));
    dbg(a, b);
    int ans = 0;
    while (n--) {
        if (abs(a.front() - b.back()) > abs(a.back() - b.front())) {
            dbg(a.front(), b.back());
            ans += abs(a.front() - b.back());
            a.pop_front();
            b.pop_back();
        }
        else {
            dbg(a.back(), b.front());
            ans += abs(a.back() - b.front());
            a.pop_back();
            b.pop_front();
        }
    }
    cout << ans << endl;
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