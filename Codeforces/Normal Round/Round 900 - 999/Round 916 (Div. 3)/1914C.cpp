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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), vis_a(n, 0), vis_b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = k; i < n; i++)
        a.pop_back(), b.pop_back();
    priority_queue<int> pq;
    int ans = 0;
    ans += a[0];
    pq.push(b[0]);
    int i = 2;
    for (int it = i; it <= k; it++) {
        int upore = pq.top();
        int sum = 0, c = 0;
        for (int j = it - 1; j < a.size(); j++) {
            sum += a[j];
            c++;
            if (a[j] >= upore) {
                break;
            }
        }
        dbg(it, c, sum, upore);
        if (c != 0) {
            if (sum >= (c * upore) ) {
                ans += sum;
                for (int j = it - 1; (j < it - 1 + c and j < b.size()); j++) {
                    pq.push(b[j]);
                    dbg(j, b[j]);
                }
                it = it + c - 1;
            }
            else {
                ans += (upore * c);
                it = it + c - 1;
            }
        }
        else
            ans += upore;
        dbg(it, c, ans);
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