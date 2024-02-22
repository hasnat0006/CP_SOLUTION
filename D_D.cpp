//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    while (dq.front() == 0 and dq.size() > 0)
        dq.pop_front();
    while (dq.back() == 0 and dq.size() > 0)
        dq.pop_back();
    n = dq.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = dq.front();
        dq.pop_front();
    }
    int baad = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0)
            zero++;
        else {
            if (zero > 1)
                baad += zero;
            zero = 0;
        }
    }
    if (zero > 1)
        baad += zero;
    cout << n - baad << endl;
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