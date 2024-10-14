//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 01:53:31            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void printing(priority_queue<int> pq) {
    while (pq.size()) {
        cerr << pq.top() << " ";
        pq.pop();
    }
    cerr << endl;
}

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0, temp, mx = -1;
    for(int i = 0; i < n; i++){
        cin >> temp;
        mx = max(mx, temp);
        sum += temp;
    } 
    int ans = sum / x + (sum % x == 0 ? 0 : 1);
    cout << max(ans, mx) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}