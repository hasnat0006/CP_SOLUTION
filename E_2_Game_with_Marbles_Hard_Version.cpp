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
    int n;
    cin >> n;
    priority_queue<pair<int, int>> a, b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push({v[i], i});
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push({x, i});
    }
    int cnt = 1;
    while (1) {
        int a_top_val = a.top().first, a_top_id = a.top().second,
            b_top_val = b.top().first, b_top_id = b.top().second;
        if(cnt % 2){
            
        }
    }
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